/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:10:06 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:01:06 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_w1(int c, unsigned char res[])
{
	res[0] = c;
	return (1);
}

int		ft_w2(int c, unsigned char res[])
{
	res[1] = (c & 0x3F) | (0x80);
	res[0] = ((c >> 6) & 0x1F) | 0xC0;
	return (2);
}

int		ft_w3(int c, unsigned char res[])
{
	if (c >= 0x800 && c <= 0xFFF)
		return (conv31(c, res));
	if (c >= 0x1000 && c <= 0x1FFF)
		return (conv32(c, res));
	if (c >= 0x2000 && c <= 0x3FFF)
		return (conv33(c, res));
	if (c >= 0x4000 && c <= 0x7FFF)
		return (conv34(c, res));
	if (c >= 0x8000 && c <= 0xBFFF)
		return (conv35(c, res));
	if (c >= 0xC000 && c <= 0xCFFF)
		return (conv36(c, res));
	if (c >= 0xD000 && c <= 0xD7FF)
		return (conv37(c, res));
	if (c >= 0xE000 && c <= 0xFFFF)
		return (conv38(c, res));
	return (3);
}

int		ft_w4(int c, unsigned char res[])
{
	if (c >= 0x10000 && c <= 0x1FFFF)
		return (conv41(c, res));
	if (c >= 0x20000 && c <= 0x3FFFF)
		return (conv42(c, res));
	if (c >= 0x40000 && c <= 0x7FFFF)
		return (conv43(c, res));
	if (c >= 0x80000 && c <= 0xFFFFF)
		return (conv44(c, res));
	if (c >= 0x100000 && c <= 0x10FFFF)
		return (conv45(c, res));
	return (4);
}

int		ft_getwint(int c, unsigned char res[])
{
	if ((c >= 0xD800 && c <= 0xDFFF) || (c > 0xD7FF && c < 0xE000) ||
			c < 0 || c == 256)
		return (-1);
	if (c <= 127)
		return (ft_w1(c, res));
	else if (c >= 0x80 && c <= 0x7FF)
		return (ft_w2(c, res));
	else if (c <= 0xFFFF)
		return (ft_w3(c, res));
	else if (c <= 0x10FFFF)
		return (ft_w4(c, res));
	return (-1);
}
