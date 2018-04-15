/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:22:58 by hlely             #+#    #+#             */
/*   Updated: 2018/04/15 16:13:29 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

t_function	g_function[] =
{
	{'s',		&ft_string},
	{'d',		&ft_int},
	{'o',		&ft_octal},
	{0,		NULL}
};

int			ft_string(va_list *arg)
{
	char	*res;

	res = va_arg(*arg, char*);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_int(va_list *arg)
{
	int		nb;
	char	*res;

	nb = va_arg(*arg, int);
	res = ft_itoa(nb);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_octal(va_list *arg)
{
	int		nb;
	char	*res;

	nb = va_arg(*arg, int);
	res = ft_itoa_base(nb, 8);
	ft_putstr(res);
	return (ft_strlen(res));
}

int ft_printf(char *str, ...)
{
	int		i;
	int		j;
	va_list	arg;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = 0;
			while (g_function[j].value)
			{
				if (g_function[j].value == str[i])
				{
					g_function[j].f(&arg);
					break ;
				}
				j++;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}
