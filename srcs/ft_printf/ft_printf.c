/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:29 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 19:31:30 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

#include "../../include/ft_printf.h"

t_function	g_function[] =
{
	{'s', &ft_string},
	{'c', &ft_char},
	{'C', &ft_char},
	{'d', &ft_int},
	{'D', &ft_int},
	{'i', &ft_int},
	{'o', &ft_octal},
	{'x', &ft_minihexa},
	{'X', &ft_maxihexa},
	{'u', &ft_uint},
	{'U', &ft_uint},
	{'%', &ft_percent},
	{0, NULL}
};

int			ft_percent(va_list *arg, t_opt opt)
{
	char	*res;

	(void)arg;
	res = ft_strdup("%");
	opt.preci = -1;
	res = handle_strflag(res, opt);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_printf(char *str, ...)
{
	int		i;
	int		j;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_putnstr(str, i);
			len += i;
			str += i + 1;
			i = 0;
			j = i;
			while (!is_converter(str[i]))
				i++;
			if (is_converter(str[i]))
				len += convert(&arg, str[i], str + j);
			str += i + 1;
			i = 0;
		}
		else
			i++;
	}
	len += ft_putnstr(str, i);
		/* printf("[%d]", len); */
	return (len);
}
