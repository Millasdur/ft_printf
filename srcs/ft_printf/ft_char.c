/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:31:40 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 20:05:30 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_char(va_list *arg, t_opt opt)
{
	int		c;
	int		len;
	char	*res;

	c = va_arg(*arg, int);
	res = ft_strnew(1);
	res[0] = (c == 0) ? '\0' : c;
	len = (c == 0) ? 1 : 0;
	res = handle_charflag(res, opt, len);
	ft_putnstr(res, ft_strlen(res) + len);
	return (ft_strlen(res) + len);
}
