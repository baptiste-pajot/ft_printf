/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 17:25:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//make && gcc -g main_test.c libftprintf.a && valgrind --leak-check=full ./test

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	int		a;
	int		b;
	int		i;
	char	*p = "tata";
	char	*p_null = NULL;

	i = 0;
	a = 0;
	b = 0;
	printf("LC_TYPE = %s\n", setlocale(LC_CTYPE, NULL));
	printf("MB_CUR_MAX = %i\n", MB_CUR_MAX);

	i++;
	printf("Test %d : printf(\"|%%lc|\\n\", 0x40501)\n", i);
	a = printf("|%lc|\n", 0x40501);
	b = ft_printf("|%lc|\n", 0x40501);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10c|\\n\", -1)\n", i);
	a = printf("|%10c|\n", -1);
	b = ft_printf("|%10c|\n", -1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10c|\\n\", -128)\n", i);
	a = printf("|%10c|\n", -128);
	b = ft_printf("|%10c|\n", -128);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10c|\\n\", -129)\n", i);
	a = printf("|%10c|\n", -129);
	b = ft_printf("|%10c|\n", -129);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|toto|\\n\")\n", i);
	a = printf("|toto|\n");
	b = ft_printf("|toto|\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%c|\\n\", 0)\n", i);
	a = printf("|%c|\n", 0);
	b = ft_printf("|%c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%c|\\n\", 132)\n", i);
	a = printf("|%c|\n", 132);
	b = ft_printf("|%c|\n", 132);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%c|\\n\", -32)\n", i);
	a = printf("|%c|\n", -32);
	b = ft_printf("|%c|\n", -32);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%cto|\\n\", 'a')\n", i);
	a = printf("|to%cto|\n", 'a');
	b = ft_printf("|to%cto|\n", 'a');
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%Cto|\\n\", L'ø')\n", i);
	setlocale(LC_ALL, "");
	a = printf("|to%Cto|\n", L'ø');
	b = ft_printf("|to%Cto|\n", L'ø');
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%Cto|\\n\", L'迿')\n", i);
	a = printf("|to%Cto|\n", L'迿');
	b = ft_printf("|to%Cto|\n", L'迿');
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%Ct&&Co|\\n\", L'🏄', L'🏂')\n", i);
	a = printf("|to%Ct%Co|\n", L'🏄', L'🏂');
	b = ft_printf("|to%Ct%Co|\n", L'🏄', L'🏂');
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%oto|\\n\", -32)\n", i);
	a = printf("|%o|\n", -32);
	b = ft_printf("|%o|\n", -32);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%o|\\n\", 2147483647)\n", i);
	a = printf("|%o|\n", 2147483647);
	b = ft_printf("|%o|\n", 2147483647);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%o|\\n\", 0)\n", i);
	a = printf("|%o|\n", 0);
	b = ft_printf("|%o|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#o|\\n\", 42)\n", i);
	a = printf("|%#o|\n", 42);
	b = ft_printf("|%#o|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%lO|\\n\", -1L)\n", i);
	a = printf("|%lO|\n", -1L);
	b = ft_printf("|%lO|\n", -1L);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%lO|\\n\", 2147483648L)\n", i);
	a = printf("|%lO|\n", 2147483648L);
	b = ft_printf("|%lO|\n", 2147483648L);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%l0|\\n\", 4200000000000L)\n", i);
	a = printf("|%lO|\n", 4200000000000L);
	b = ft_printf("|%lO|\n", 4200000000000L);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%x|\\n\", 0)\n", i);
	a = printf("|%x|\n", 0);
	b = ft_printf("|%x|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%x|\\n\", 4235478)\n", i);
	a = printf("|%x|\n", 4235478);
	b = ft_printf("|%x|\n", 4235478);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%x|\\n\", -42)\n", i);
	a = printf("|%x|\n", -42);
	b = ft_printf("|%x|\n", -42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#x|\\n\", 42)\n", i);
	a = printf("|%#x|\n", 42);
	b = ft_printf("|%#x|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%X|\\n\", 0)\n", i);
	a = printf("|%X|\n", 0);
	b = ft_printf("|%X|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%X|\\n\", 4235478)\n", i);
	a = printf("|%X|\n", 4235478);
	b = ft_printf("|%X|\n", 4235478);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%X|\\n\", -42)\n", i);
	a = printf("|%X|\n", -42);
	b = ft_printf("|%X|\n", -42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#X|\\n\", 42)\n", i);
	a = printf("|%#X|\n", 42);
	b = ft_printf("|%#X|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+i|\\n\", 0)\n", i);
	a = printf("|%+i|\n", 0);
	b = ft_printf("|%+i|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%% d|\\n\", 0)\n", i);
	a = printf("|% d|\n", 0);
	b = ft_printf("|% d|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+-5d|\\n\", -42)\n", i);
	a = printf("|%+-5d|\n", -42);
	b = ft_printf("|%+-5d|\n", -42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+05d|\\n\", 42)\n", i);
	a = printf("|%+05d|\n", 42);
	b = ft_printf("|%+05d|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%-05d|\\n\", 42)\n", i);
	a = printf("|%-5d|\n", 42);
	b = ft_printf("|%-5d|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%lD|\\n\", 0L)\n", i);
	a = printf("|%lD|\n", 0L);
	b = ft_printf("|%lD|\n", 0L);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.3%%|\\n\")\n", i);
	a = printf("|%.3%|\n");
	b = ft_printf("|%.3%|\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#o|\\n\", 0)\n", i);
	a = printf("|%#o|\n", 0);
	b = ft_printf("|%#o|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.3c|\\n\", 0)\n", i);
	a = printf("|%.3c|\n", 0);
	b = ft_printf("|%.3c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%3c|\\n\", 0)\n", i);
	a = printf("|%3c|\n", 0);
	b = ft_printf("|%3c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.2c|\\n\", 0)\n", i);
	a = printf("|%.2c|\n", 0);
	b = ft_printf("|%.2c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%2c|\\n\", 0)\n", i);
	a = printf("|%2c|\n", 0);
	b = ft_printf("|%2c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.c|\\n\", 0)\n", i);
	a = printf("|%.c|\n", 0);
	b = ft_printf("|%.c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%15.4o|\\n\", 424242)\n", i);
	a = printf("|%15.4o|\n", 424242);
	b = ft_printf("|%15.4o|\n", 424242);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%p|\\n\", p)\n", i);
	a = printf("|%p|\n", p);
	b = ft_printf("|%p|\n", p);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%p|\\n\", p_null)\n", i);
	a = printf("|%p|\n", p_null);
	b = ft_printf("|%p|\n", p_null);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%9.2p|\\n\", 1234)\n", i);
	a = printf("|%9.2p|\n", 1234);
	b = ft_printf("|%9.2p|\n", 1234);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.5p|\\n\", 0)\n", i);
	a = printf("|%.5p|\n", 0);
	b = ft_printf("|%.5p|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%5Y|\\n\")\n", i);
	a = printf("|%5Y|\n");
	b = ft_printf("|%5Y|\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.5Y|\\n\")\n", i);
	a = printf("|%.5Y|\n");
	b = ft_printf("|%.5Y|\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%s|\\n\", NULL)\n", i);
	a = printf("|%s|\n", NULL);
	b = ft_printf("|%s|\n", NULL);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%s|\", \"z123a\")\n", i);
	a = printf("|to%s|\n", "z123a");
	b = ft_printf("|to%s|\n", "z123a");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%5.3s|\\n\", NULL)\n", i);
	a = printf("|%5.3s|\n", NULL);
	b = ft_printf("|%5.3s|\n", NULL);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|to%%5.3s|\", \"z1\")\n", i);
	a = printf("|to%5.3s|\n", "z1");
	b = ft_printf("|to%5.3s|\n", "z1");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.4S|\",\"...\")\n", i);
	a = printf("|%.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	b = ft_printf("|%.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%15.4S|\",\"...\")\n", i);
	a = printf("|%15.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	b = ft_printf("|%15.4S|\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.4S|\",\"...\")\n", i);
	a = printf("|%.4S|\n", L"我是一只猫。");
	b = ft_printf("|%.4S|\n", L"我是一只猫。");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%15.4S|\",\"...\")\n", i);
	a = printf("|%15.4S|\n", L"我是一只猫。");
	b = ft_printf("|%15.4S|\n", L"我是一只猫。");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%lc|\",\'...\')\n", i);
	a = printf("|%lc|\n", L'米');
	b = ft_printf("|%lc|\n", L'米');
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.c|\", 42)\n", i);
	a = printf("|%05.c|\n", 42);
	b = ft_printf("|%05.c|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%c|\", 0)\n", i);
	a = printf("|%c|\n", 0);
	b = ft_printf("|%c|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.c|\", 0)\n", i);
	a = printf("|%05.c|\n", 42);
	b = ft_printf("|%05.c|\n", 42);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.C|\", 0)\n", i);
	a = printf("|%05.C|\n", 0);
	b = ft_printf("|%05.C|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.s|\", 0)\n", i);
	a = printf("|%05.s|\n", 0);
	b = ft_printf("|%05.s|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.0%%|\", 0)\n", i);
	a = printf("|%05.0%|\n", 0);
	b = ft_printf("|%05.0%|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.%%|\", 0)\n", i);
	a = printf("|%05.%|\n", 0);
	b = ft_printf("|%05.%|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%05.Z|\", 0)\n", i);
	a = printf("|%05.Z|\n", 0);
	b = ft_printf("|%05.Z|\n", 0);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#.5x|\", 1)\n", i);
	a = printf("|%#.5x|\n", 1);
	b = ft_printf("|%#.5x|\n", 1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#10.2x|\", 1)\n", i);
	a = printf("|%#10.2x|\n", 1);
	b = ft_printf("|%#10.2x|\n", 1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%#.5o|\", 1)\n", i);
	a = printf("|%#.5o|\n", 1);
	b = ft_printf("|%#.5o|\n", 1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%.5p|\", 1)\n", i);
	a = printf("|%.5p|\n", 1);
	b = ft_printf("|%.5p|\n", 1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"{%%05.c}\", 42)\n", i);
	a = printf("{%05.c}", 42);
	printf("\n");
	b = ft_printf("{%05.c}", 42);
	printf("\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"{%%.0c}\", 42)\n", i);
	a = printf("{%.0c}", 42);
	printf("\n");
	b = ft_printf("{%.0c}", 42);
	printf("\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"{%%0.3c}\", 42)\n", i);
	a = printf("{%0.3c}", 42);
	printf("\n");
	b = ft_printf("{%0.3c}", 42);
	printf("\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%d|\\n\", 323)\n", i);
	a = printf("|%d|\n", 323);
	b = ft_printf("|%d|\n", 323);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+5.5lD|\\n\", -9223372036854775807L)\n", i);
	a = printf("|%+5.5lD|\n", -9223372036854775807L);
	b = ft_printf("|%+5.5lD|\n", -9223372036854775807L);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+d|\\n\", 323)\n", i);
	a = printf("|%+d|\n", 323);
	b = ft_printf("|%+d|\n", 323);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%hhd|\\n\", 128)\n", i);
	a = printf("|%hhd|\n", 128);
	b = ft_printf("|%hhd|\n", 128);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%zhd|\\n\", 4294967295)\n", i);
	a = printf("|%zhd|\n", 4294967295);
	b = ft_printf("|%zhd|\n", 4294967295);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%hhld|\\n\", 9223372036854775807)\n", i);
	a = printf("|%hhld|\n", 9223372036854775807);
	b = ft_printf("|%hhld|\n", 9223372036854775807);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%####0000 33..1..#00d|\\n\", 256)\n", i);
	a = printf("|%####0000 33..1..#00d|\n", 256);
	b = ft_printf("|%####0000 33..1..#00d|\n", 256);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%##-##0000 33..12..#0+0d|\\n\", 256)\n", i);
	a = printf("|%##-##0000 33..12..#0+0d|\n", 256);
	b = ft_printf("|%##-##0000 33..12..#0+0d|\n", 256);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%15.4S|\",\"...\")\n", i);
	a = printf("|%15.4S|\n", L"我是一只猫。");
	b = ft_printf("|%15.4S|\n", L"我是一只猫。");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%60.4S|\",\"...\")\n", i);
	a = printf("|%60.4S|\n", L"我是一只猫。");
	b = ft_printf("|%60.4S|\n", L"我是一只猫。");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%61.4S|\",\"...\")\n", i);
	a = printf("|%61.4S|\n", L"我是一只猫。");
	b = ft_printf("|%61.4S|\n", L"我是一只猫。");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%hhp|\\n\", p)\n", i);
	a = printf("|%hhp|\n", p);
	b = ft_printf("|%hhp|\n", p);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%llp|\\n\", p)\n", i);
	a = printf("|%llp|\n", p);
	b = ft_printf("|%llp|\n", p);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%48.13ji|\\n\", -1)\n", i);
	a = printf("|%48.13ji|\n", -1);
	b = ft_printf("|%48.13ji|\n", -1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%+.12ji|\\n\", -2031434840)\n", i);
	a = printf("|%+.12ji|\n", -2031434840);
	b = ft_printf("|%+.12ji|\n", -2031434840);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("ggreturn value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%4.2ls|\\n\", NULL)\n", i);
	a = printf("|%4.2ls|\n", NULL);
	b = ft_printf("|%4.2ls|\n", NULL);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%2.10ls|\\n\", NULL)\n", i);
	a = printf("|%2.10ls|\n", NULL);
	b = ft_printf("|%2.10ls|\n", NULL);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10lc|\\n\", 0x20000)\n", i);
	a = printf("|%10lc|\n", 0x20000);
	b = ft_printf("|%10lc|\n", 0x20000);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10lc|\\n\", 0x200000)\n", i);
	a = printf("|%10lc|\n", 0x200000);
	b = ft_printf("|%10lc|\n", 0x200000);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10C|\\n\", -1)\n", i);
	a = printf("|%10C|\n", -1);
	b = ft_printf("|%10C|\n", -1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10c|\\n\", (char)-1)\n", i);
	a = printf("|%10c|\n", (char)-1);
	b = ft_printf("|%10c|\n", (char)-1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%10c|  |%%10c|\\n\", -1, -1)\n", i);
	a = printf("|%10c|  |%10c|\n", -1, -1);
	b = ft_printf("|%10c|  |%10c|\n", -1, -1);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%C|\\n\", 0x11ffff)\n", i);
	a = printf("|%C|\n", 0x11ffff);
	b = ft_printf("|%C|\n", 0x11ffff);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%lc|\\n\", 0x40501)\n", i);
	a = printf("%lc", 0x40501);
	printf("\n");
	b = ft_printf("%lc", 0x40501);
	printf("\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%c|\\n\", -21)\n", i);
	a = printf("%c", -21);
	printf("\n");
	b = ft_printf("%c", -21);
	printf("\n");
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return value NOK !!!\n", i);
	ft_putendl("");

	printf("LC_TYPE = %s\n", setlocale(LC_CTYPE, NULL));
	printf("MB_CUR_MAX = %i\n", MB_CUR_MAX);
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("UCHAR_MAX : %d\n", UCHAR_MAX);
	printf("INT_MIN : %d\n", INT_MIN);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("UINT_MAX : %u\n", UINT_MAX);
	printf("LONG_MIN : %ld\n", LONG_MIN);
	printf("LONG_MAX : %ld\n", LONG_MAX);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("WCHAR_MIN : %d\n", WCHAR_MIN);
	printf("WCHAR_MAX : %d\n", WCHAR_MAX);
	printf("WINT_MIN : %d\n", WINT_MIN);
	printf("WINT_MAX : %d\n", WINT_MAX);

	return (0);
}
