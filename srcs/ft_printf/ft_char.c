/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:31:40 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 16:46:33 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handle_lc(int c, t_opt *opt)
{
	int		len;
	char	tmp[5];
	char	*res;

	ft_bzero(tmp, 5);
	len = ft_getwint(c, tmp);
	if (len == -1)
		return (NULL);
	res = ft_strdup(tmp);
	res = handle_strflag(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += opt->len2;
	return (res);
}

char		*ft_wchar(va_list *arg, t_opt *opt)
{
	intmax_t	c;
	int			len;
	char		*res;

	c = va_arg(*arg, intmax_t);
	if (c == 0)
	{
		res = ft_strnew(1);
		res[0] = (c == 0) ? '\0' : c;
		len = (c == 0) ? 1 : 0;
		res = handle_charflag(res, *opt, len);
		opt->len2 = opt->width ? opt->width : ft_strlen(res) + len;
		opt->len += opt->len2;
	}
	else
		res = handle_lc(c, opt);
	return (res);
}

char		*ft_char(va_list *arg, t_opt *opt)
{
	intmax_t	c;
	int			len;
	char		*res;

	c = va_arg(*arg, intmax_t);
	if (opt->modif & L_MODE)
		res = handle_lc(c, opt);
	else
	{
		res = ft_strnew(1);
		res[0] = (c == 0) ? '\0' : c;
		len = (c == 0) ? 1 : 0;
		res = handle_charflag(res, *opt, len);
		opt->len2 = opt->width ? opt->width : ft_strlen(res) + len;
		opt->len += opt->len2;
	}
	return (res);
}
