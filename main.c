/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/27 16:30:01 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");
	wint_t i = 0x20AC;
	char	*test = "test";
	/* wchar_t i = €; */
	
	/* ft_printf("%lc", 254); */
	/* printf("%lc", 254); */

	ft_printf("% d", 0);
	/* ft_printf("%lc\n", 0x40501); */

	/* ft_printf("{%05.S}", L"42 c est cool"); */
	/* printf("{%05.S}", L"42 c est cool"); */

	/* printf("%S\n", L""); */
	/* ft_printf("%S", 0); */
	/* printf("%S", 0); */
	/* printf("%lc\n", 0x40501); */
	/* printf("%lc, %lc", L'ÊM-^ZM-^V', L'ÿ≠'); */

	/* printf("\n%d\n", printf("€")); */
	return (0);
}
