/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:50 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/17 18:43:04 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_intlen(int n)
{
	int			len;
	long long	nn;

	len = 0;
	nn = n;
	if (nn <= 0)
		len++;
	while (nn != 0)
	{
		nn /= 10;
		len++;
	}
	return (len);
}

static void	get_sign_info(int n, t_info *info, char *sign, int *sign_len)
{
	*sign_len = 0;
	*sign = 0;
	if (n < 0)
	{
		*sign_len = 1;
		*sign = '-';
	}
	else if (info->flag[0] == '+')
	{
		*sign_len = 1;
		*sign = '+';
	}
	else if (info->flag[0] == ' ')
	{
		*sign_len = 1;
		*sign = ' ';
	}
}

static int	get_padding(int num_len, int sign_len, t_info *info)
{
	if (info->width > num_len + sign_len)
		return (info->width - num_len - sign_len);
	return (0);
}

static void	print_number(int n, char sign, int padding, t_info *info)
{
	if (info->flag[0] == '-')
	{
		if (sign)
			ft_putchar_fd(sign, 1);
		ft_putnbr_fd(n, 1);
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (info->flag[1] == '0')
	{
		if (sign)
			ft_putchar_fd(sign, 1);
		while (padding-- > 0)
			ft_putchar_fd('0', 1);
		ft_putnbr_fd(n, 1);
	}
	else
	{
		while (padding-- > 0)
			ft_putchar_fd(' ', 1);
		if (sign)
			ft_putchar_fd(sign, 1);
		ft_putnbr_fd(n, 1);
	}
}

int	ft_solve_di(t_info *info)
{
	int		n;
	int		len;
	int		sign_len;
	int		padding;
	char	sign;

	n = va_arg(info->arguments, int);
	len = ft_intlen(n);
	get_sign_info(n, info, &sign, &sign_len);
	padding = get_padding(len - (n < 0), sign_len, info);
	len += sign_len;
	print_number(n, sign, padding, info);
	if (info->width > len)
		return (info->width);
	return (len);
}
