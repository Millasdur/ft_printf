/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:02:02 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 14:13:18 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindel(char *s1, const char *s2)
{
	int		size;
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		res = ft_strnew(size);
		if (res != NULL)
		{
			res = ft_strcat(res, s1);
			ft_strdel(&s1);
			res = ft_strcat(res, s2);
			return (res);
		}
	}
	else if (!s1 && s2)
	{
		res = ft_strdup(s2);
		return (res);
	}
	return (NULL);
}

char	*ft_strnjoindel(char *s1, char *s2, int len1, int len2)
{
	int		size;
	char	*res;

	if (s1 && s2)
	{
		size = len1 + len2;
		if ((res = ft_strnew(size)))
		{
			res = ft_ncat(res, s1, 0, len1);
			ft_strdel(&s1);
			res = ft_ncat(res, s2, len1, len2);
			return (res);
		}
	}
	if (!s1 && s2)
	{
		res = ft_strnew(len2);
		res = ft_ncat(res, s2, 0, len2);
		return (res);
	}
	return (NULL);
}
