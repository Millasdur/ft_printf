/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:09:26 by hlely             #+#    #+#             */
/*   Updated: 2018/04/16 18:03:33 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_converter(char c)
{
	int		j;

	j = 0;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
			return (1);
		j++;
	}
	return (0);
}

int			convert(va_list *arg, char c, char *flags)
{
	int		j;
	int		len;
	t_opt	opt;

	j = 0;
	len = 0;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
		{
			opt = get_attr(flags);
/* check_flag(opt.flags); */
/* check_modif(opt.modif); */
			len = g_function[j].f(arg, opt);
			break ;
		}
		j++;
	}
	return (len);
}
