/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:22:27 by hlely             #+#    #+#             */
/*   Updated: 2018/04/16 16:17:34 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_flag(int flags)
{
	flags & HASH ? ft_printf("Hash\t\t: 1\n") : ft_printf("Hash\t\t: 0\n");
	flags & MINUS ? ft_printf("Minus\t\t: 1\n") : ft_printf("minus\t\t: 0\n");
	flags & PLUS ? ft_printf("Plus\t\t: 1\n") : ft_printf("Plus\t\t: 0\n");
	flags & SPACE ? ft_printf("Space\t\t: 1\n") : ft_printf("Space\t\t: 0\n");
}

void		check_modif(int flags)
{
	flags & J_MODE ? ft_printf("j\t\t: 1\n") : ft_printf("j\t\t: 0\n");
	flags & Z_MODE ? ft_printf("z\t\t: 1\n") : ft_printf("z\t\t: 0\n");
	flags & L_MODE ? ft_printf("l\t\t: 1\n") : ft_printf("l\t\t: 0\n");
	flags & LL_MODE ? ft_printf("ll\t\t: 1\n") : ft_printf("ll\t\t: 0\n");
	flags & H_MODE ? ft_printf("h\t\t: 1\n") : ft_printf("h\t\t: 0\n");
	flags & HH_MODE ? ft_printf("hh\t\t: 1\n") : ft_printf("hh\t\t: 0\n");
}

t_opt		get_flag(char *str, t_opt opt)
{
	int		i;
	int		flags;

	i = 0;
	flags = 0;
	while (str[i] && !is_converter(str[i]))
	{
		flags |= (str[i] == '#') ? HASH : flags;
		flags |= (str[i] == '+') ? PLUS : flags;
		flags |= (str[i] == '-') ? MINUS : flags;
		flags |= (str[i] == ' ') ? SPACE : flags;
		i++;
	}
	opt.flags = flags;
	return (opt);
}
