/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:11:55 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 13:17:01 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_uint(va_list *arg, t_opt opt)
{
	uintmax_t				nb;
	char					*res;

	nb = get_unumber(arg, opt);
	opt.flags &= ~PLUS;
	opt.flags &= ~SPACE;
	res = ft_uitoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, INT);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_umaxiint(va_list *arg, t_opt opt)
{
	uintmax_t				nb;
	char					*res;

	nb = get_unumber(arg, opt);
	opt.flags &= ~PLUS;
	opt.modif |= L_MODE;
	opt.modif &= ~H_MODE;
	opt.modif &= ~HH_MODE;
	opt.flags &= ~SPACE;
	res = ft_uitoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, INT);
	ft_putstr(res);
	return (ft_strlen(res));
}
