/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:56:21 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 09:35:41 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int			ft_int(va_list *arg, t_opt opt)
{
	long long int		nb;
	char				*res;

	nb = get_number(arg, opt);
	if (nb < 0)
	{
		opt.positive = 0;
		opt.flags |= PLUS;
		nb = -nb;
	}
	res = ft_itoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, INT);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_uint(va_list *arg, t_opt opt)
{
	unsigned long long int		nb;
	char						*res;

	nb = get_unumber(arg, opt);
	opt.flags &= ~PLUS;
	opt.flags &= ~SPACE;
	res = ft_itoa_base(nb, 10);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, INT);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_octal(va_list *arg, t_opt opt)
{
	long long int		nb;
	char	*res;

	nb = get_number(arg, opt);
	opt.flags ^= (nb == 0 && opt.preci != 0) ? (opt.flags & HASH) : 0;
	res = ft_itoa_base(nb, 8);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, OCT);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			ft_minihexa(va_list *arg, t_opt opt)
{
	long long int		nb;
	char	*res;

	nb = get_number(arg, opt);
	opt.flags ^= (nb == 0) ? (opt.flags & HASH) : 0;
	if (nb < 0)
		res = ft_itoa_base(4294967296 + nb, 16);
	else
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
}

int			ft_maxihexa(va_list *arg, t_opt opt)
{
	long long int		nb;
	char	*res;

	nb = get_number(arg, opt);
	opt.flags ^= (nb == 0) ? (opt.flags & HASH) : 0;
	if (nb < 0)
		res = ft_itoa_base(4294967296 + nb, 16);
	else
		res = ft_itoa_base(nb, 16);
	if (ft_strequ(res, "0") && opt.preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	res = handle_number_flag(res, &opt, MHEX);
	ft_putstr(res);
	return (ft_strlen(res));
}
