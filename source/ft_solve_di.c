/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:50 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 18:25:11 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"


int ft_intlen(int n)
{
    int len = 0;

    if (n <= 0)  
        len++;  
    while (n != 0)
    {
        n /= 10;  
        len++;
    }
    return len;
}

int ft_solve_di(t_info *info)
{
    int n = va_arg(info->arguments, int);
    int len = ft_intlen(n);  
    int padding = info->width - len;

    if (n >= 0 && (info->flag[0] == '+' || info->flag[0] == ' '))
        len++;

    if (info->flag[1] == '0' && info->flag[0] != '-') {
        
        if (n >= 0 && (info->flag[0] == '+' || info->flag[0] == ' ')) {
            ft_putchar_fd(info->flag[0], 1);  
            len++;
        }
        while (padding-- > 0)
            ft_putchar_fd('0', 1);
    } else if (info->flag[0] == '-') {
        // Alineación a la izquierda
        ft_putnbr_fd(n, 1);
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);  
        return len + padding;  
    } else {
        
        while (padding-- > 0)
            ft_putchar_fd(' ', 1);
        ft_putnbr_fd(n, 1);
    }

    return len + padding;
}