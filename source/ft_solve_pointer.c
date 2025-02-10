/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:52 by m.chiri           #+#    #+#             */
/*   Updated: 2024/11/21 19:37:03 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_putnbr_base(unsigned long n, const char *base)
{
    int len = 0;
    if (n >= 16)
        len += ft_putnbr_base(n / 16, base);
    ft_putchar_fd(base[n % 16], 1);
    len++;
    return len;
}

int ft_solve_pointer(t_info *info)
{
    void *ptr = va_arg(info->arguments, void*);
    
    // Si el puntero es NULL, imprimir "(nil)"
    if (ptr == NULL)
    {
        ft_putstr_fd("(nil)", 1);
        return 5; // Longitud de "(nil)"
    }

    // Imprimir el puntero en formato hexadecimal
    ft_putstr_fd("0x", 1);
    return ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
}
