/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:35:25 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:17:19 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_cs(char **res, wchar_t c, t_opt *opt)
{
	int				len;
	unsigned char	tmp[5];

	ft_bzero(tmp, 5);
	len = ft_getwint(c, tmp);
	if (len == -1)
		return (-1);
	if (opt->preci == -1 ||
			(opt->preci >= 0 && (int)ft_strlen(*res) + len <= opt->preci))
		*res = ft_strjoindel(*res, (char*)tmp);
	return (0);
}

char		*ft_bigstring(va_list *arg, t_opt *opt)
{
	wchar_t	*str;
	char	*res;

	res = NULL;
	str = va_arg(*arg, wchar_t*);
	if (str == NULL)
	{
		res = ft_strdup("(null)");
		res = handle_strflag(res, *opt);
		opt->len2 = ft_strlen(res);
		opt->len += ft_strlen(res);
		return (res);
	}
	while (str && *str)
	{
		if (handle_cs(&res, *str, opt) == -1)
			return (NULL);
		str++;
	}
	res = handle_strwidth(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += opt->len2;
	return (res);
}

char		*ft_string(va_list *arg, t_opt *opt)
{
	char	*res;

	if (opt->modif & L_MODE)
		return (ft_bigstring(arg, opt));
	res = va_arg(*arg, char*);
	if (res == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(res);
	res = handle_strflag(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
