/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:45:00 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/28 18:11:33 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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

int	ft_solve_hex(t_info *info)
{
	unsigned int	n;
	int				len;

	n = va_arg(info->arguments, unsigned int);
	len = ft_hexlen(n);
	ft_putnbr_hex_fd(n, 1, *info->format);
	return (len);
}
