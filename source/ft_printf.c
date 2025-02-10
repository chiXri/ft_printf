/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 18:38:01 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

// Procesa los flags antes de la conversión
// Procesa los flags antes de la conversión
int ft_process_flags(t_info *info)
{
    // Inicializa las flags
    info->flag[0] = '\0'; 
    info->flag[1] = '\0';

    // Procesa los flags uno por uno
    while (*info->format == '-' || *info->format == '0' || *info->format == '+' || *info->format == ' ')
    {
        if (*info->format == '-')
            info->flag[0] = '-';  // Alineación a la izquierda
        else if (*info->format == '0')
            info->flag[1] = '0';  // Relleno con ceros
        else if (*info->format == '+')
            info->flag[0] = '+';  // Mostrar signo explícito
        else if (*info->format == ' ')
            info->flag[0] = ' ';  // Espacio delante de números positivos
        info->format++;  // Avanza al siguiente carácter
    }
    return 0;
}

// Función principal ft_printf
int ft_printf(const char *format, ...)
{
    t_info *info;
    int length = 0;

    // Inicializa la estructura info
    info = (t_info *)ft_calloc(1, sizeof(t_info));
    va_start(info->arguments, format);
    info->format = format;

    // Itera a través del formato de texto
    while (*info->format)
    {
        // Imprime caracteres normales
        while (*info->format && *info->format != '%')
        {
            ft_putchar_fd(*info->format, 1);
            info->total_length++;
            info->format++;
        }

        // Si encontramos un '%', procesamos el especificador de formato
        if (*info->format && *info->format == '%')
        {
            info->format++; // Avanza al siguiente carácter después de '%'
            ft_process_flags(info);  // Procesa los flags antes de continuar

            // Procesa los diferentes especificadores de formato
            if (*info->format == 'd' || *info->format == 'i')
                info->total_length += ft_solve_di(info);  // Llama a la función para enteros
            else if (*info->format == 'u')
                info->total_length += ft_solve_uint(info);  // Llama a la función para unsigned int
            else if (*info->format == 'x' || *info->format == 'X')
                info->total_length += ft_solve_hex(info);  // Llama a la función para hexadecimales
            else if (*info->format == 's')
                info->total_length += ft_solve_string(info);  // Llama a la función para strings
            else if (*info->format == 'c')
                info->total_length += ft_solve_char(info);  // Llama a la función para caracteres
            else if (*info->format == '%')
                info->total_length += ft_solve_percent(info);  // Llama a la función para '%' literal
            else
                ft_putstr_fd("[ERROR]->", 1);  // Si el especificador es desconocido
            info->format++;  // Avanza al siguiente carácter
        }
    }

    va_end(info->arguments); // Finaliza el uso de va_list
    length = info->total_length;
    free(info); // Libera la memoria
    return (length);
}