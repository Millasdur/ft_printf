/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 16:44:37 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	wint_t i = 0x20AC;
	/* wchar_t i = €; */
	
	ft_printf("%lc", 0x11FFFF);
	/* printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠'); */

	/* printf("\n%d\n", printf("€")); */
	return (0);
}
