/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:42:34 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 16:23:47 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pointer(va_list *arg, t_opt opt)
{
	uintmax_t	nb;
	char		*res;

	opt.modif |= L_MODE;
	nb = get_unumber(arg, opt);
	opt.flags |= HASH;
	res = ft_uitoa_base(nb, 16);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	ft_lowercase(&res);
	res = handle_number_flag(res, &opt, POINT);
	ft_putstr(res);
	return (ft_strlen(res));
	return (ft_strlen(res));
}
