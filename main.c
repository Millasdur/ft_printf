/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 14:34:45 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	long	i = 4294967295;
	/* unsigned short i = 4294967296; */
	/* float f = 1.23; */
	/* float g = 1; */
	/* float h = 0.123; */
	/* int	u = 1; */
	/* char *str1 = "bonjour1"; */
	/* char *str2 = "bonjour2"; */
	/* wchar_t *test = "bonjour"; */

	/* printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string"); */
	/* ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string"); */
	/* ft_printf("%d"); */
	/* printf("%10s\n", NULL); */
	/* ft_printf("%10s\n", NULL); */
	/* printf("test[%C]\n", 42); */
	/* ft_printf("mine[%C]\n", 42); */
	/* printf("test[%3c]\n", 42); */
	/* ft_printf("mine[%3c]\n", 42); */
	/* printf("test[%c]\n", 0); */
	/* ft_printf("mine[%c]\n", 0); */
	/* ft_printf("-----\n%s-----\n", "bonjour"); */
	
	printf("[%o %O]\n", 42, 42);
	ft_printf("|%o %O|\n", 42, 42);
	printf("[%lo %lo]\n", 0, ULONG_MAX);
	ft_printf("|%lo %lo|\n", 0, ULONG_MAX);
	return (0);
}
