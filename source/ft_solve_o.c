/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:00:00 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/07 12:00:14 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Función para imprimir un número en formato octal
void ft_putnbr_octal_fd(unsigned int n, int fd)
{
    if (n >= 8)
        ft_putnbr_octal_fd(n / 8, fd);  // Recursividad para convertir a octal
    write(fd, &"01234567"[n % 8], 1);   // Imprime el dígito octal
}

// Función para obtener la longitud de un número en octal
int ft_octal_len(unsigned int n)
{
    int len = 0;
    if (n == 0)
        return 1; // El número 0 tiene longitud 1
    while (n)
    {
        len++;
        n /= 8;  // Dividir entre 8 para contar los dígitos octales
    }
    return len;
}

// Función para manejar la conversión de enteros con signos y octales
int ft_solve_o(t_info *info)
{
    unsigned int n = va_arg(info->arguments, unsigned int);
    int len = ft_octal_len(n);  // Calculamos la longitud del número octal
    int padding = info->width - len;
    int total_len = len;

    // Si el flag '#' está presente, agregar el prefijo '0'
    if (info->flag[0] == '#')
    {
        if (n != 0)
        {
            ft_putchar_fd('0', 1);  // Prefijo "0" solo si el número no es 0
            total_len++;  // El prefijo "0" añade 1 carácter a la longitud total
        }
    }

    // Rellenar con ceros o espacios si corresponde
    if (info->flag[1] == '0' && info->flag[0] != '-')
    {
        while (padding-- > 0)
            ft_putchar_fd('0', 1);  // Rellenamos con ceros
    }
    else if (info->flag[0] != '-')
    {
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);  // Rellenamos con espacios
    }

    // Imprimir el número en octal
    ft_putnbr_octal_fd(n, 1);

    // Si el flag '-' está presente, rellenar con espacios a la derecha
    if (info->flag[0] == '-')
    {
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);
    }

    return total_len + (padding > 0 ? padding : 0);  // Retornar la longitud total
}