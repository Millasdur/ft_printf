/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:26:01 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 16:41:12 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_number(va_list *arg, t_opt opt)
{
	long long int	nb;

	nb = va_arg(*arg, long long int);
	nb = (opt.modif & J_MODE) ? (intmax_t)nb : nb;
	nb = (opt.modif & Z_MODE) ? (size_t)nb : nb;
	nb = (opt.modif & HH_MODE) ? (signed char)nb : nb;
	nb = (opt.modif & H_MODE) ? (short int)nb : nb;
	nb = (opt.modif & L_MODE) ? (long int)nb : nb;
	nb = (opt.modif & LL_MODE) ? (long long int)nb : nb;
	nb = (opt.modif == 0) ? (int)nb : nb;
	return (nb);
}

long long	get_unumber(va_list *arg, t_opt opt)
{
	unsigned long long int	nb;

	nb = va_arg(*arg, unsigned long long int);
	nb = (opt.modif & J_MODE) ? (uintmax_t)nb : nb;
	nb = (opt.modif & Z_MODE) ? (size_t)nb : nb;
	nb = (opt.modif & HH_MODE) ? (unsigned char)nb : nb;
	nb = (opt.modif & H_MODE) ? (unsigned short int)nb : nb;
	nb = (opt.modif & L_MODE) ? (unsigned long int)nb : nb;
	nb = (opt.modif & LL_MODE) ? (unsigned long long int)nb : nb;
	nb = (opt.modif == 0) ? (unsigned int)nb : nb;
	return (nb);
}
