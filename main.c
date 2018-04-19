/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/19 10:15:28 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
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
	unsigned long i = 0;
	
	printf("[%+o]\n", 42);
	ft_printf("|%+o|\n", 42);
	return (0);
}
