/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:22:58 by hlely             #+#    #+#             */
/*   Updated: 2018/04/13 15:07:25 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int ft_printf(char *str, ...)
{
	int		i;
	va_list	arg;
	char	*res;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's')
			{
				res = va_arg(arg, char*);
				ft_putstr(res);
				i++;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}
