/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:13 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/28 18:12:18 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

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
	{
		ft_putchar_fd('%', 1);//1
		ft_putchar_fd(*info->format, 1);//2
		info->total_length += 2;
	}
	info->format++;
	//1 y //2 La funcion original cunado NO encuentra un caracter de formateo despues de un procentaje da un wanrning al compilador, si compilas sin las flags
	//lo que hace es sacar por pantalla solo el porcentaje pero el carater que va desoues del porcentaje se lo salta (no lo imprime) ni lo cuenta (no hace len++), si ciompilas con las flags (-Werror -Wextra ...), el compilador 
	//lo bloquea. Tedrias dos opciones o hacer un va_end en ese caso o dejarlo como lo tienes y  hacer que imprima el porcentaje, hacer len += 1 y hacer que se salte el siguiente caracter (el que no existe).
	//printf("%t"); solo impirme el porcentaje porque la t no es un caracter de formateo.
}

int	ft_process_format(t_info *info)
{
	while (*info->format)
	{
		while (*info->format && *info->format != '%')
		{
			ft_putchar_fd(*info->format, 1);
			info->total_length++;
			info->format++;
		}
		if (*info->format == '%')//aqui oudes tener un priblema, porque si el siguiente caracter es el '\0' se lo vas a pasar a ft_process conversion
		{
			info->format++;
			ft_process_conversion(info);
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_info		*info;
	int			length;
	const char	*format_copy;

	if (!format)
		return (-1);  //1 
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		return (-1);
	info->total_length = 0;
	va_start(info->arguments, format);
	format_copy = format;
	info->format = format_copy;  //2
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
	// 1: La funcion printf no puede tener el argumento format apunado a NULL, cunado intentas compilarlo no te deja el compilador asi que eso no haria falta auqnue no creo que sea motivo para que te lo tiren, otra cosa en la MOulinette
	// 2 aqui puedes hacer directamente "info->format = format;" y quitar la linea anterior
}
