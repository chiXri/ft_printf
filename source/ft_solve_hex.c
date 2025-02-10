/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:21 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 20:04:29 by m.chiri          ###   ########.fr       */
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

int ft_solve_hex(t_info *info) {
    unsigned int n = va_arg(info->arguments, unsigned int);
    int len = ft_hexlen(n);
    int padding = info->width - len;

    if (info->flag[0] == '#') {
        if (n != 0) {
            ft_putchar_fd('0', 1);  // Prefijo "0"
            ft_putchar_fd(*info->format == 'x' ? 'x' : 'X', 1);  // Prefijo "0x" o "0X"
            len += 2;  // El prefijo añade 2 a la longitud
        }
    }

    if (info->flag[1] == '0' && info->flag[0] != '-') {
        while (padding-- > 0) ft_putchar_fd('0', 1);  // Relleno con ceros
    }

    if (*info->format == 'x')
        ft_putnbr_hex_fd(n, 1);  // Imprime en minúsculas
    else if (*info->format == 'X')
        ft_putnbr_hex_fd_upper(n, 1);  // Imprime en mayúsculas

    if (info->flag[0] == '-') {
        while (padding-- > 0) ft_putchar_fd(' ', 1);  // Relleno con espacios a la derecha
    }

    return len + (padding < 0 ? 0 : padding);  // Retorna la longitud total
}
