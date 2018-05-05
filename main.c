/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:12:09 by hlely            ###   ########.fr       */
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


	/* ft_printf("[%#051.28llO]\n", 392202497589131190); */
	/* printf("{%#051.28llO}\n", 392202497589131190); */

	/* ft_printf("[%#-042o]\n", 42); */
	/* printf("{%#0-42o}\n", 42); */

	/* ft_printf("[%#62o]\n", 42); */
	/* printf("{%#62o}\n", 42); */

	/* ft_printf("[%#04o]\n", 42); */
	/* printf("{%#04o}\n", 42); */

	/* ft_printf("[%-#59.24o]\n", 42); */
	/* printf("{%-#59.24o}\n", 42); */

	/* ft_printf("[%-#28.4hho]\n", -1971135752); */
	/* printf("{%-#28.4hho}\n", -1971135752); */

	/* ft_printf("[%#51.2jo]\n", 42); */
	/* printf("{%#51.2jo}\n", 42); */

	/* ft_printf("[%0#14.0o]\n", 42); */
	/* printf("{%0#14.0o}\n", 42); */

	/* ft_printf("[!%-#29.2o!]\n", 42); */
	/* printf("{!%-#29.2o!}\n", 42); */

	/* ft_printf("[%#-26.2hho]\n", 706850312); */
	/* printf("{%#-26.2hho}\n", 706850312); */

	ft_printf("[42%56.32lc42]\n", L'ËM-^N®');
	printf("[42%56.32lc42]\n", L'ËM-^N®');




	/* ft_printf("[%0#14.0o]\n", 42); */
	/* printf("{%0#14.0o}\n", 42); */
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
