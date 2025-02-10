/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:48:17 by m.chiri           #+#    #+#             */
/*   Updated: 2024/11/21 19:37:08 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

// Función que imprime un número unsigned int
void ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
    if (n >= 10)
        ft_putnbr_unsigned_fd(n / 10, fd);  // Llamada recursiva para separar los dígitos
    write(fd, &"0123456789"[n % 10], 1);  // Escribir el dígito actual
}

// Función que calcula la longitud de un unsigned int
int ft_uintlen(unsigned int n)
{
    int len = 0;

    if (n == 0)
        len = 1; // El número 0 tiene una longitud de 1
    while (n != 0)
    {
        n /= 10;  // Dividimos entre 10 para contar los dígitos
        len++;
    }
    return len;
}

// Función que resuelve el caso de %u
int ft_solve_uint(t_info *info)
{
    unsigned int n = va_arg(info->arguments, unsigned int); // Extraemos el unsigned int
    ft_putnbr_unsigned_fd(n, 1); // Lo imprimimos usando la nueva función
    return (ft_uintlen(n)); // Retornamos la longitud del unsigned int
}
