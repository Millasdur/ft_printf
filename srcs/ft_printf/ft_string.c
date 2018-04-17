/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:35:25 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 17:35:42 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_string(va_list *arg, t_opt opt)
{
	char	*res;

	(void)opt;
	res = va_arg(*arg, char*);
	ft_putstr(res);
	return (ft_strlen(res));
}
