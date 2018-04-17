/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 20:04:49 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int i = -42;
	/* float f = 1.23; */
	/* float g = 1; */
	/* float h = 0.123; */
	/* int	u = 1; */
	char *str1 = "bonjour1";
	char *str2 = "bonjour2";

	short test = (short)i;
	/* printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string"); */
	ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	/* ft_printf("%d"); */
	/* printf("%10s\n", NULL); */
	/* ft_printf("%10s\n", NULL); */
	printf("test[%C]\n", 42);
	/* ft_printf("mine[%C]\n", 42); */
	printf("test[%3c]\n", 42);
	ft_printf("mine[%3c]\n", 42);
	printf("test[%c]\n", 0);
	ft_printf("mine[%c]\n", 0);
	/* ft_printf("-----\n%s-----\n", "bonjour"); */
	
	return (0);
}
