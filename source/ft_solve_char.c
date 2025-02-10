/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:05:50 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/07 12:18:13 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_solve_char(t_info *info)
{
    char c = (char)va_arg(info->arguments, int);  // Obtenemos el carácter como int y lo convertimos a char
    ft_putchar_fd(c, 1);  // Imprimimos el carácter
    return (1);  // Retornamos la longitud
}