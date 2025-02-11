/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:00:00 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/11 15:42:59 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putnbr_octal_fd(unsigned int n, int fd)
{
	if (n >= 8)
		ft_putnbr_octal_fd(n / 8, fd);
	write(fd, &"01234567"[n % 8], 1);
}

int	ft_octal_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 8;
	}
	return (len);
}

int	ft_solve_o(t_info *info)
{
	unsigned int	n;
	int				len;
	int				padding;
	int				total_len;

	n = va_arg(info->arguments, unsigned int);
	len = ft_octal_len(n);
	padding = info->width - len;
	total_len = len;
	if (info->flag[2] == '#')
	{
		if (n != 0)
		{
			ft_putchar_fd('0', 1);
			total_len++;
		}
	}
	if (info->flag[1] == '0' && info->flag[0] != '-')
	{
		while (padding-- > 0)
			ft_putchar_fd('0', 1);
	}
	else if (info->flag[0] != '-')
	{
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
	}
	ft_putnbr_octal_fd(n, 1);
	if (info->flag[0] == '-')
	{
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
	}
	return (total_len + (padding > 0 ? padding : 0));
}
