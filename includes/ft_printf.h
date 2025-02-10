/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:01:30 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/10 20:42:15 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

/*
**  ft_printf str length for "(nill)"
*/
# ifndef NULL_SIZE
#  define NULL_SIZE 6
# endif

enum				e_flags
{
	e_minus,
	e_zero
};

enum				e_dispatch
{
	e_char,
	e_string,
	e_pointer,
	e_decimal_int,
	e_u_dec_int,
	e_u_hex_int,
	e_percentage,
	e_length
};

typedef struct s_info
{
    const char  *format;
    va_list     arguments;
    int         total_length;
    int         width;
	char        flag[3];  // Añadido para almacenar los flags

} t_info;


/*
**  ft_printf solution functions
*/

int					ft_printf(const char *format, ...);
int     			ft_solve_char(t_info *info);
int     			ft_solve_string(t_info *info);
int     			ft_solve_pointer(t_info *info);
int     			ft_solve_di(t_info *info);
int     			ft_solve_uint(t_info *info);
int     			ft_solve_hex(t_info *info);
int     			ft_solve_percent(t_info *info);
int 				ft_solve_o(t_info *info);

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

#endif
