/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:21 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/17 19:03:00 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h" 

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putnbr_hex_fd_helper(unsigned int n, int fd, const char *base)
{
	if (n >= 16)
		ft_putnbr_hex_fd_helper(n / 16, fd, base);
	write(fd, &base[n % 16], 1);
}

static void	ft_putnbr_hex_fd(unsigned int n, int fd, char specifier)
{
	if (specifier == 'x')
		ft_putnbr_hex_fd_helper(n, fd, "0123456789abcdef");
	else if (specifier == 'X')
		ft_putnbr_hex_fd_helper(n, fd, "0123456789ABCDEF");
}

static int	ft_handle_flags(t_info *info, unsigned int n, int len)
{
	int	padding;

	padding = info->width - len;
	if (info->flag[0] == '#')
	{
		if (n != 0)
		{
			ft_putchar_fd('0', 1);
			if (*info->format == 'x')
				ft_putchar_fd('x', 1);
			else
				ft_putchar_fd('X', 1);
			len += 2;
		}
	}
	if (info->flag[1] == '0' && info->flag[0] != '-')
	{
		while (padding-- > 0)
			ft_putchar_fd('0', 1);
	}
	return (padding);
}

int	ft_solve_hex(t_info *info)
{
	unsigned int	n;
	int				len;
	int				padding;

	n = va_arg(info->arguments, unsigned int);
	len = ft_hexlen(n);
	padding = ft_handle_flags(info, n, len);
	ft_putnbr_hex_fd(n, 1, *info->format);
	if (info->flag[0] == '-')
	{
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
	}
	if (padding < 0)
		return (len);
	return (len + padding);
}
