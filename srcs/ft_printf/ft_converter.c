/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:09:26 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:35:04 by hlely            ###   ########.fr       */
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
			len = g_function[j].f(arg, opt);
			return (len);
		}
		j++;
	}
	opt = get_attr(flags);
	opt.charac = c;
	len = ft_else(arg, opt);
	return (len);
}
