/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:33:54 by hlely             #+#    #+#             */
/*   Updated: 2018/04/16 19:00:43 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_hash(char *src, t_opt opt, int type)
{
	char	*tmp;

	tmp = src;
	if (opt.flags & HASH)
	{
		if (type == OCT && !ft_strequ(src, "0"))
			tmp = ft_strjoin("0", src);
		else if (type == OCT && ft_strequ(src, "0"))
			return (src);
		else if (type == HEX && ft_strequ(src, "0"))
			return (src);
		else if (type == HEX)
			tmp = ft_strjoin("0x", src);
		else if (type == MHEX && ft_strequ(src, "0"))
			return (src);
		else if (type == MHEX)
			tmp = ft_strjoin("0X", src);
		ft_strdel(&src);
		return (tmp);
	}
	return (src);
}

char	*handle_preci(char *src, int preci)
{
	int		len;
	char	*tmp;

	len = preci - ft_strlen(src);
	if (len <= 0)
		return (src);
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = ft_strjoindel(tmp, "0");
		len--;
	}
	tmp = ft_strjoindel(tmp, src);
	ft_strdel(&src);
	return (tmp);
}

char	*handle_width(char *src, t_opt opt)
{
	int		len;
	char	*tmp;

	len = opt.width - ft_strlen(src);
	len = ((opt.flags & HASH) && !ft_strequ(src, "0")) ? len - 2 : len;
	if (len <= 0)
		return (src);
	tmp = ft_strdup("");
	while (len > 0)
	{
		tmp = (opt.zero == 1 && opt.preci == -1 && (opt.flags & MINUS) == 0) ?
			ft_strjoindel(tmp, "0") : ft_strjoindel(tmp, " ");
		len--;
	}
	if (opt.flags & MINUS)
		tmp = ft_strjoinddel(src, tmp);
	else
	{
		tmp = ft_strjoindel(tmp, src);
		ft_strdel(&src);
	}
	return (tmp);
}

char	*handle_number_flag(char *src, t_opt opt, int type)
{
	src = handle_preci(src, opt.preci);
	src = handle_hash(src, opt, type);
	src = handle_width(src, opt);
	return (src);
}
