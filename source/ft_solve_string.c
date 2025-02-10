/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:57 by m.chiri           #+#    #+#             */
/*   Updated: 2024/11/21 19:37:06 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_solve_string(t_info *info)
{
	char *str = va_arg(info->arguments, char *); // Extraemos la cadena
	if (!str)
		str = "(null)"; // Si es NULL, mostramos "(null)"
	ft_putstr_fd(str, 1); // Imprimimos la cadena
	return (ft_strlen(str)); // Retornamos la longitud de la cadena
}
