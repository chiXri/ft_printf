/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m.chiri <m.chiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:01:30 by m.chiri           #+#    #+#             */
/*   Updated: 2025/02/17 19:41:48 by m.chiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

# ifndef NULL_SIZE
#  define NULL_SIZE 6
# endif

typedef struct s_info
{
	const char	*format;
	va_list		arguments;
	int			total_length;
	int			width;
	char		flag[3];

}				t_info;

int				ft_printf(const char *format, ...);
int				ft_solve_char(t_info *info);
int				ft_solve_string(t_info *info);
int				ft_solve_pointer(t_info *info);
int				ft_solve_di(t_info *info);
int				ft_solve_uint(t_info *info);
int				ft_solve_hex(t_info *info);
int				ft_solve_percent(t_info *info);
int				ft_solve_o(t_info *info);

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

#endif
