/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:10:06 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 07:57:45 by hlely            ###   ########.fr       */
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
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x1F) | 0xA0;
		res[0] = 0xE0;
	}
	if (c >= 0x1000 && c <= 0x1FFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = 0xE1;
	}
	if (c >= 0x2000 && c <= 0x3FFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = ((c >> 12) & 0x1) | 0xE2;
	}
	if (c >= 0x4000 && c <= 0x7FFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = ((c >> 12) & 0x3) | 0xE4;
	}
	if (c >= 0x8000 && c <= 0xBFFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = ((c >> 12) & 0x3) & 0xE8;
	}
	if (c >= 0xC000 && c <= 0xCFFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = 0xEC;
	}
	if (c >= 0xD000 && c <= 0xD7FF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x1F) | 0x9F;
		res[0] = 0xED;
	}
	if (c >= 0xE000 && c <= 0xFFFF)
	{
		res[2] = (c & 0x3F) | (0x80);
		res[1] = ((c >> 6) & 0x3F) | 0x80;
		res[0] = ((c >> 12) & 0x1) | 0xEE;
	}
	return (3);
}

int		ft_w4(int c, unsigned char res[])
{
	if (c >= 0x10000 && c <= 0x1FFFF)
	{
		res[3] = (c & 0x3F) | (0x80);
		res[2] = ((c >> 6) & 0x3F) | 0x80;
		res[1] = ((c >> 12) & 0xF) | 0x90;
		res[0] = 0xF0;
	}
	if (c >= 0x20000 && c <= 0x3FFFF)
	{
		res[3] = (c & 0x3F) | (0x80);
		res[2] = ((c >> 6) & 0x3F) | 0x80;
		res[1] = ((c >> 12) & 0x1F) | 0xA0;
		res[0] = 0xF0;
	}
	if (c >= 0x40000 && c <= 0x7FFFF)
	{
		res[3] = (c & 0x3F) | (0x80);
		res[2] = ((c >> 6) & 0x3F) | 0x80;
		res[1] = ((c >> 12) & 0x3F) | 0x80;
		res[0] = 0xF1;
	}
	if (c >= 0x80000 && c <= 0xFFFFF)
	{
		res[3] = (c & 0x3F) | (0x80);
		res[2] = ((c >> 6) & 0x3F) | 0x80;
		res[1] = ((c >> 12) & 0x3F) | 0x80;
		res[0] = ((c >> 18) & 0x1) | 0xF2;
	}
	if (c >= 0x100000 && c <= 0x10FFFF)
	{
		res[3] = (c & 0x3F) | (0x80);
		res[2] = ((c >> 6) & 0x3F) | 0x80;
		res[1] = ((c >> 12) & 0xF) | 0x80;
		res[0] = 0xF4;
	}
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
