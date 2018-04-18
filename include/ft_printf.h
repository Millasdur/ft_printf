/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:26:19 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 08:43:20 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
						# include <stdio.h>
# include "libft.h"

# define HASH		1
# define MINUS		2
# define PLUS		4
# define SPACE		8

# define J_MODE		1
# define Z_MODE		2
# define HH_MODE	4
# define H_MODE		8
# define L_MODE		16
# define LL_MODE	32
# define NONE		64

# define INT		1
# define OCT		2
# define HEX		3
# define MHEX		4

typedef struct	s_opt
{
	int		positive;
	int		preci;
	int		width;
	int		modif;
	int		zero;
	int		flags;
}				t_opt;

typedef struct	s_function
{
	char	value;
	int		(*f)(va_list*, t_opt);
}				t_function;

extern t_function	g_function[];

int		ft_printf(char *str, ...);
int		ft_string(va_list *arg, t_opt opt);
int		ft_pointer(va_list *arg, t_opt opt);
int		ft_char(va_list *arg, t_opt opt);
int		ft_percent(va_list *arg, t_opt opt);
int		ft_int(va_list *arg, t_opt opt);
int		ft_uint(va_list *arg, t_opt opt);
int		ft_octal(va_list *arg, t_opt opt);
int		ft_minihexa(va_list *arg, t_opt opt);
int		ft_maxihexa(va_list *arg, t_opt opt);

void	check_flag(int flags);
void	check_modif(int flags);
int		is_converter(char c);
int		convert(va_list *arg, char c, char *flags);

t_opt	get_attr(char *str);
t_opt	get_flag(char *str, t_opt opt);

char	*handle_number_flag(char *src, t_opt *opt, int type);
char	*handle_hash(char *src, t_opt *opt, int type);
char	*handle_plus_space(char *src, t_opt *opt, int type);

long long int	get_number(va_list *arg, t_opt opt);
long long int	get_unumber(va_list *arg, t_opt opt);

char			*handle_strflag(char *src, t_opt opt);
char			*handle_charflag(char *src, t_opt opt, int len);
#endif

