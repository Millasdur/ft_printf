/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 08:42:34 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 08:59:33 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pointer(va_list *arg, t_opt opt)
{
	long long int		nb;
	char	*res;

	nb = get_number(arg, opt);
	opt.flags |= HASH;
	opt.flags ^= (nb == 0) ? (opt.flags & HASH) : 0;
	res = ft_itoa_base(nb, 16);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	ft_lowercase(&res);
	res = handle_number_flag(res, &opt, HEX);
	ft_putstr(res);
	return (ft_strlen(res));
	return (ft_strlen(res));
}
