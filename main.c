/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/25 17:40:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	wint_t i = 0x20AC;
	/* wchar_t i = €; */
	
	ft_printf("{%05.S}", L"42 c est cool");
	printf("{%05.S}", L"42 c est cool");
	/* printf("%S\n", L""); */
	/* ft_printf("%S", 0); */
	/* printf("%S", 0); */
	/* printf("%lc\n", 0x40501); */
	/* printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠'); */

	/* printf("\n%d\n", printf("€")); */
	return (0);
}
