/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:10:06 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 17:10:17 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_w1(wchar_t c, char res[])
{
	res[0] = c;
	return (1);
}

int		ft_w2(wchar_t c, char res[])
{
	res[1] = (c & 0x3F) | (0x80);
	res[0] = (c >> 6) | 0xC0;
	return (2);
}

int		ft_w3(wchar_t c, char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | (0x80);
	res[0] = (c >> 12) | (0xE0);
	return (3);
}

int		ft_w4(wchar_t c, char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | (0x80);
	res[1] = ((c >> 12) & 0x3F) | (0x80);
	res[0] = (c >> 16) | (0xF0);
	return (1);
}

int		ft_getwint(wchar_t c, char res[])
{
	if (c <= 0x7F)
		return (ft_w1(c, res));
	else if (c <= 0x7FF)
		return (ft_w2(c, res));
	else if (c <= 0xFFFF)
		return (ft_w3(c, res));
	else if (c <= 0x10FFFF)
		return (ft_w4(c, res));
	return (-1);
}
