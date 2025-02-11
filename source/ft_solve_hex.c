/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:10:21 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/11 15:42:13 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putnbr_hex_fd(unsigned int n, int fd)
{
	if (n >= 16)
		ft_putnbr_hex_fd(n / 16, fd);
	write(fd, &"0123456789abcdef"[n % 16], 1);
}

void	ft_putnbr_hex_fd_upper(unsigned int n, int fd)
{
	if (n >= 16)
		ft_putnbr_hex_fd_upper(n / 16, fd);
	write(fd, &"0123456789ABCDEF"[n % 16], 1);
}

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

int	ft_solve_hex(t_info *info)
{
	unsigned int	n;
	int				len;
	int				padding;

	n = va_arg(info->arguments, unsigned int);
	len = ft_hexlen(n);
	padding = info->width - len;
	if (info->flag[0] == '#')
	{
		if (n != 0)
		{
			ft_putchar_fd('0', 1);
			ft_putchar_fd(*info->format == 'x' ? 'x' : 'X', 1);
			len += 2;
		}
	}
	if (info->flag[1] == '0' && info->flag[0] != '-')
	{
		while (padding-- > 0)
			ft_putchar_fd('0', 1);
	}
	if (*info->format == 'x')
		ft_putnbr_hex_fd(n, 1);
	else if (*info->format == 'X')
		ft_putnbr_hex_fd_upper(n, 1);
	if (info->flag[0] == '-')
	{
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
	}
	return (len + (padding < 0 ? 0 : padding));
}
