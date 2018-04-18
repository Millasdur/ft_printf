/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_else.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:30:32 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:37:18 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_else(va_list *arg, t_opt opt)
{
	char	*res;

	(void)arg;
	res = ft_strdup((char*)&opt.charac);
	opt.preci = -1;
	res = handle_strflag(res, opt);
	ft_putstr(res);
	return (ft_strlen(res));
}
