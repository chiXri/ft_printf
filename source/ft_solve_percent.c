/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:47:52 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/07 12:17:25 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_solve_percent(t_info *info)
{
    (void)info;  // Evita la advertencia por no usar el parámetro
    ft_putchar_fd('%', 1);  // Imprime el símbolo '%' literalmente
    return (1);  // Retorna la longitud del carácter '%'
}
