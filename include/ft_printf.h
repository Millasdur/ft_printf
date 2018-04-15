/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:26:19 by hlely             #+#    #+#             */
/*   Updated: 2018/04/15 16:00:38 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
						# include <stdio.h>
# include "../srcs/libft/libft.h"

typedef struct	s_function
{
	char	value;
	int		(*f)(va_list*);
}				t_function;

int		ft_printf(char *str, ...);
int		ft_string(va_list *arg);
int		ft_int(va_list *arg);
int		ft_octal(va_list *arg);

#endif

