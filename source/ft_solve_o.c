/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:00 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/28 18:11:48 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_octal_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 8;
		len++;
	}
	return (len);
}

void	ft_putnbr_octal_fd(unsigned int n, int fd)
{
	if (n >= 8)
		ft_putnbr_octal_fd(n / 8, fd);
	write(fd, &"01234567"[n % 8], 1);
}

int	ft_solve_o(t_info *info)
{
	unsigned int	n;
	int				len;

	n = va_arg(info->arguments, unsigned int);
	len = ft_octal_len(n);
	ft_putnbr_octal_fd(n, 1);
	return (len);
}
