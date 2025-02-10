/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 20:42:14 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
int ft_process_flags(t_info *info)
{
    // Inicializa las flags
    info->flag[0] = '\0';
    info->flag[1] = '\0';

    // Procesa los flags uno por uno
    while (*info->format == '-' || *info->format == '0' || *info->format == '+' || *info->format == ' ' || *info->format == '#')
    {
        if (*info->format == '-')
            info->flag[0] = '-';  // Alineación a la izquierda
        else if (*info->format == '0')
            info->flag[1] = '0';  // Relleno con ceros
        else if (*info->format == '+')
            info->flag[0] = '+';  // Mostrar signo explícito
        else if (*info->format == ' ')
            info->flag[0] = ' ';  // Espacio delante de números positivos
        else if (*info->format == '#')
            info->flag[2] = '#';  // Guardamos el flag '#' en una nueva posición
        info->format++;  // Avanza al siguiente carácter
    }
    return 0;
}

// Procesa los flags antes de la conversión
int ft_printf(const char *format, ...)
{
    t_info *info;
    int length = 0;

    info = (t_info *)ft_calloc(1, sizeof(t_info));
    va_start(info->arguments, format);
    info->format = format;

    while (*info->format)
    {
        while (*info->format && *info->format != '%')
        {
            ft_putchar_fd(*info->format, 1);
            info->total_length++;
            info->format++;
        }

        if (*info->format && *info->format == '%')
        {
            info->format++;
            ft_process_flags(info);

            // *** AÑADIDO: Extraer el ancho ***
            info->width = 0; // Inicializar el ancho
            while (ft_isdigit(*info->format))
            {
                info->width = info->width * 10 + (*info->format - '0');
                info->format++;
            }
            // *** FIN DE AÑADIDO ***

            // Procesamiento de conversiones
            if (*info->format == 'd' || *info->format == 'i')
                info->total_length += ft_solve_di(info);
            else if (*info->format == 'u')
                info->total_length += ft_solve_uint(info);
            else if (*info->format == 'x' || *info->format == 'X')
                info->total_length += ft_solve_hex(info);
            else if (*info->format == 'o')  // Asegúrate de manejar 'o' para octales
                info->total_length += ft_solve_o(info);  // Llamada a tu ft_solve_o
            else if (*info->format == 's')
                info->total_length += ft_solve_string(info);
            else if (*info->format == 'c')
                info->total_length += ft_solve_char(info);
            else if (*info->format == '%')
                info->total_length += ft_solve_percent(info);
            else
                ft_putstr_fd("[ERROR]->", 1);
            info->format++;  // Avanzamos al siguiente carácter
        }
    }

    va_end(info->arguments);
    length = info->total_length;
    free(info);
    return (length);
}
