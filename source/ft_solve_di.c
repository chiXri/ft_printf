/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:50 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 20:20:53 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_intlen(int n) {
    int len = 0;
    long long nn = n;
    if (nn <= 0) len++;
    while (nn != 0) {
        nn /= 10;
        len++;
    }
    return len;
}

int ft_solve_di(t_info *info) {
    int n = va_arg(info->arguments, int);
    int len = ft_intlen(n);
    int width = info->width;
    int padding = 0;
    int sign_len = 0;
    char sign = 0;
    int num_len = len; // Guarda la longitud del número sin el signo

    if (n < 0) {
        sign_len = 1;
        sign = '-';
        num_len--; // Restamos 1 a num_len si es negativo para el padding
    } else if (info->flag[0] == '+') {
        sign_len = 1;
        sign = '+';
    } else if (info->flag[0] == ' ') {
        sign_len = 1;
        sign = ' ';
    }

    // Calculamos el padding.  Importante: Usamos num_len y width
    if (width > num_len + sign_len) {
        padding = width - num_len - sign_len;
    }

    len += sign_len;


    if (info->flag[0] == '-') { // Caso: Flag '-'
        if (sign) ft_putchar_fd(sign, 1);
        ft_putnbr_fd(n, 1);
        while (padding-- > 0) ft_putchar_fd(' ', 1);

    } else if (info->flag[1] == '0') { // Caso: Flag '0'
        if (sign) ft_putchar_fd(sign, 1);
        while (padding-- > 0) ft_putchar_fd('0', 1);
        ft_putnbr_fd(n, 1);

    } else { // Caso: Sin flag '-' ni '0'
        while (padding-- > 0) ft_putchar_fd(' ', 1);
        if (sign) ft_putchar_fd(sign, 1);
        ft_putnbr_fd(n, 1);
    }

    return (width > len ? width : len);
}