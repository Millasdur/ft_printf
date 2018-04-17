/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:06:21 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 16:07:13 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_opt	get_preci(char *str, t_opt opt)
{
	char	*tmp;

	if ((tmp = ft_strrchr(str, '.')) == NULL)
		return (opt);
	if (*(tmp + 1))
		opt.preci = ft_atoi(tmp + 1);
	return (opt);
}

t_opt	get_width(char *str, t_opt opt)
{
	int		i;

	i = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.'
			&& (!ft_isdigit(str[i]) || str[i] == '0'))
		i++;
	opt.width = ft_atoi(str + i);
	return (opt);
}

t_opt	get_zero(char *str, t_opt opt)
{
	int		i;

	i = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.'
			&& !ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '0')
		opt.zero = 1;
	return (opt);
}

t_opt	get_modif(char *str, t_opt opt)
{
	int		i;

	i = 0;
	while (str[i] && !is_converter(str[i]))
	{
		if (ft_strchr("lhjz", str[i]))
		{
			if (str[i] == 'l' && str[i + 1] && str[i + 1] == 'l')
				opt.modif = LL_MODE;
			else if (str[i] == 'l' && str[i + 1] && str[i + 1] != 'l')
				opt.modif = L_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] == 'h')
				opt.modif = HH_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] != 'h')
				opt.modif = H_MODE;
			else if (str[i] == 'j')
				opt.modif = J_MODE;
			else if (str[i] == 'z')
				opt.modif = Z_MODE;
		}
		i += (opt.modif == HH_MODE || opt.modif == LL_MODE) ? 2 : 1;
	}
	return (opt);
}

t_opt	get_attr(char *str)
{
	t_opt	opt;

	opt.positive = 1;
	opt.preci = -1;
	opt.width = 0;
	opt.modif = 0;
	opt.zero = 0;
	opt = get_width(str, opt);
	opt = get_preci(str, opt);
	opt = get_zero(str, opt);
	opt = get_flag(str, opt);
	opt = get_modif(str, opt);
	/* printf("largeur\t\t: %d\n", opt.width); */
	/* printf("precision\t: %d\n", opt.preci); */
	/* printf("zero\t\t: %d\n", opt.zero); */
	return (opt);
}
