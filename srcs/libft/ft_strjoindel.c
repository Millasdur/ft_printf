/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:02:02 by hlely             #+#    #+#             */
/*   Updated: 2018/04/18 15:39:00 by hlely            ###   ########.fr       */
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
