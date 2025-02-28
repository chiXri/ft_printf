/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:52 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/28 18:13:16 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_putnbr_base(unsigned long n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_base(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}

int	ft_solve_pointer(t_info *info)
{
	void	*ptr;
	int		len;

	ptr = va_arg(info->arguments, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	len = 2;
	len += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
