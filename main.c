/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:31:52 by hlely             #+#    #+#             */
/*   Updated: 2018/04/17 16:48:44 by hlely            ###   ########.fr       */
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
	printf("test=|%lu|\n", -42);
	ft_printf("mine=|%lu|\n", -42);
	/* ft_printf("-----\n%s-----\n", "bonjour"); */
	
	return (0);
}
