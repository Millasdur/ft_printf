/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:29 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 16:36:28 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_function	g_function[] =
{
	{'s', &ft_string},
	{'p', &ft_pointer},
	{'c', &ft_char},
	{'C', &ft_char},
	{'d', &ft_int},
	{'D', &ft_maxiint},
	{'i', &ft_int},
	{'o', &ft_octal},
	{'O', &ft_maxioctal},
	{'x', &ft_minihexa},
	{'X', &ft_maxihexa},
	{'u', &ft_uint},
	{'U', &ft_umaxiint},
	{'%', &ft_percent},
	{0, NULL}
};

int			is_attr(char c)
{
	if (ft_strchr("0123456789.-+ #lhjz", c))
		return (1);
	return (0);
}

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

int			prepare_convertion(va_list *arg, char **str, int *i, int len)
{
	int		j;

	ft_putnstr(*str, *i);
	len += *i;
	*str += *i + 1;
	*i = 0;
	j = *i;
	while ((*str)[*i] && is_attr((*str)[*i]))
		(*i)++;
	len += convert(arg, (*str)[*i], *str + j);
	*str += *i + 1;
	*i = 0;
	return (len);
}

int			ft_printf(char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			len = prepare_convertion(&arg, &str, &i, len);
		else
			i++;
	}
	len += ft_putnstr(str, i);
	return (len);
}
