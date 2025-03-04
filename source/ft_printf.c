/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/03/04 11:04:02 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void    ft_process_conversion(t_info *info)
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
    {
        ft_putchar_fd('%', 1);
        info->total_length++;
    }
    if (*info->format)
        info->format++;
}

int    ft_process_format(t_info *info)
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
            if (*info->format)
                ft_process_conversion(info);
        }
    }
    return (0);
}

int    ft_printf(const char *format, ...)
{
    t_info        *info;
    int            length;

    if (!format)
        return (-1);
    info = (t_info *)ft_calloc(1, sizeof(t_info));
    if (!info)
        return (-1);
    info->total_length = 0;
    va_start(info->arguments, format);
    info->format = format;
    if (ft_process_format(info) == -1)
    {
        va_end(info->arguments);
        free(info);
        return (-1);
    }
    va_end(info->arguments);
    length = info->total_length;
    free(info);
    return (length);
}
