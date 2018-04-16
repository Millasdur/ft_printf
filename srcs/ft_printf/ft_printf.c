/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:29 by hlely             #+#    #+#             */
/*   Updated: 2018/04/16 16:26:52 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

#include "../../include/ft_printf.h"

t_function	g_function[] =
{
	{'s', &ft_string},
	{'d', &ft_int},
	{'o', &ft_octal},
	{'x', &ft_minihexa},
	{'X', &ft_maxihexa},
	{'%', &ft_percent},
	{0, NULL}
};

int			ft_string(va_list *arg, t_opt opt)
{
	char	*res;

	(void)opt;
	res = va_arg(*arg, char*);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_percent(va_list *arg, t_opt opt)
{
	(void)arg;
	(void)opt;
	ft_putstr("%");
	return (1);
}

int			ft_printf(char *str, ...)
{
	int		i;
	int		j;
	int		flags;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	flags = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = i;
			while (!is_converter(str[i]))
				i++;
			if (is_converter(str[i]))
				len = convert(&arg, str[i], str + j);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	return (len);
}
