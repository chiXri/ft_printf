/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:21 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/07 12:17:49 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Función para imprimir el número en formato hexadecimal en minúsculas
void ft_putnbr_hex_fd(unsigned int n, int fd) {
    if (n >= 16)
        ft_putnbr_hex_fd(n / 16, fd);
    write(fd, &"0123456789abcdef"[n % 16], 1);  // Imprime en minúsculas
}

// Función para imprimir el número en formato hexadecimal en mayúsculas
void ft_putnbr_hex_fd_upper(unsigned int n, int fd) {
    if (n >= 16)
        ft_putnbr_hex_fd_upper(n / 16, fd);
    write(fd, &"0123456789ABCDEF"[n % 16], 1);  // Imprime en mayúsculas
}

// Función para obtener la longitud del número hexadecimal
int ft_hexlen(unsigned int n) {
    int len = 0;
    if (n == 0)
        return 1;
    while (n) {
        len++;
        n /= 16;  // Divide entre 16 para obtener los dígitos hexadecimales
    }
    return len;
}

// Función para resolver la impresión de números hexadecimales
int ft_solve_hex(t_info *info)
{
    unsigned int n = va_arg(info->arguments, unsigned int);
    int len = ft_hexlen(n);
    int padding = info->width - len;

    // Si el flag '#' está presente, agregar el prefijo '0x' o '0X'
    if (info->flag[0] == '#')
    {
        if (n != 0)
        {
            ft_putchar_fd('0', 1);  // Imprimir el '0'
            if (*info->format == 'x')
                ft_putchar_fd('x', 1);  // Imprimir 'x' para minúsculas
            else if (*info->format == 'X')
                ft_putchar_fd('X', 1);  // Imprimir 'X' para mayúsculas
            len += 2;  // El prefijo "0x" o "0X" agrega 2 caracteres
        }
    }

    // Rellenar con ceros si el flag '0' está presente y no hay '-'
    if (info->flag[1] == '0' && info->flag[0] != '-')
    {
        while (padding-- > 0)
            ft_putchar_fd('0', 1);  // Rellenar con ceros
    }

    // Imprimir el número hexadecimal
    if (*info->format == 'x')
        ft_putnbr_hex_fd(n, 1);  // Minúsculas
    else if (*info->format == 'X')
        ft_putnbr_hex_fd_upper(n, 1);  // Mayúsculas

    // Si el flag '-' está presente, rellenar con espacios a la derecha
    if (info->flag[0] == '-')
    {
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);  // Rellenar con espacios a la derecha
    }

    return len + (padding < 0 ? 0 : padding);  // Retorna la longitud total considerando el padding
}
