/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/17 19:35:39 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

int	ft_process_flags(t_info *info)
{
	info->flag[0] = '\0';
	info->flag[1] = '\0';
	while (*info->format == '-' || *info->format == '0' || *info->format == '+'
		|| *info->format == ' ' || *info->format == '#')
	{
		if (*info->format == '-')
			info->flag[0] = '-';
		else if (*info->format == '0')
			info->flag[1] = '0';
		else if (*info->format == '+')
			info->flag[0] = '+';
		else if (*info->format == ' ')
			info->flag[0] = ' ';
		else if (*info->format == '#')
			info->flag[2] = '#';
		info->format++;
	}
	return (0);
}

void	ft_process_width(t_info *info)
{
	info->width = 0;
	while (ft_isdigit(*info->format))
	{
		info->width = info->width * 10 + (*info->format - '0');
		info->format++;
	}
}

void	ft_process_conversion(t_info *info)
{
	if (*info->format == 'd' || *info->format == 'i')
		info->total_length += ft_solve_di(info);
	else if (*info->format == 'u')
		info->total_length += ft_solve_uint(info);
	else if (*info->format == 'x' || *info->format == 'X')
		info->total_length += ft_solve_hex(info);
	else if (*info->format == 'o')
		info->total_length += ft_solve_o(info);
	else if (*info->format == 's')
		info->total_length += ft_solve_string(info);
	else if (*info->format == 'c')
		info->total_length += ft_solve_char(info);
	else if (*info->format == '%')
		info->total_length += ft_solve_percent(info);
	else if (*info->format == 'p')
		info->total_length += ft_solve_pointer(info);
	else
		ft_putstr_fd("[ERROR]->", 1);
	info->format++;
}

void	ft_process_format(t_info *info)
{
	while (*info->format)
	{
		while (*info->format && *info->format != '%')
		{
			ft_putchar_fd(*info->format, 1);
			info->total_length++;
			info->format++;
		}
		if (*info->format == '%')
		{
			info->format++;
			ft_process_flags(info);
			ft_process_width(info);
			ft_process_conversion(info);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	t_info	*info;
	int		length;

	length = 0;
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	va_start(info->arguments, format);
	info->format = format;
	ft_process_format(info);
	va_end(info->arguments);
	length = info->total_length;
	free(info);
	return (length);
}
