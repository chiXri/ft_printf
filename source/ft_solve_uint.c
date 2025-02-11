/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:48:17 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/11 15:44:15 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

int	ft_uintlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_solve_uint(t_info *info)
{
	unsigned int	n;

	n = va_arg(info->arguments, unsigned int);
	ft_putnbr_unsigned_fd(n, 1);
	return (ft_uintlen(n));
}
