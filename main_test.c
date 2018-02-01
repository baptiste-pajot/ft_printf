/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 16:59:09 by bpajot      ###    #+. /#+    ###.fr     */
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

	i = 0;
	a = 0;
	b = 0;
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
	printf("Test %d : printf(\"|to%%+5.5dto|\\n\", 323)\n", i);
	a = printf("|to%+5.5dto|\n", 323);
	b = ft_printf("|to%+5.5dto|\n", 323);
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
	printf("Test %d : printf(\"|to%%+5.5lDto|\\n\", -9223372036854775807L)\n", i);
	a = printf("|to%+5.5lDto|\n", -9223372036854775807L);
	b = ft_printf("|to%+5.5lDto|\n", -9223372036854775807L);
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
	printf("Test %d : printf(\"|to%%s  \", \"z123a\")\n", i);
	a = printf("|to%s  ", "z123a");
	printf("\n");
	b = ft_printf("|to%s  ", "z123a");
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
	printf("Test %d : printf(\"|to%%cto|\\n\", 0)\n", i);
	a = printf("|to%cto|\n", 0);
	b = ft_printf("|to%cto|\n", 0);
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
	printf("Test %d : printf(\"|to%%sto|\\n\", NULL)\n", i);
	a = printf("|to%sto|\n", NULL);
	b = ft_printf("|to%sto|\n", NULL);
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
	a = printf("|to%oto|\n", -32);
	b = ft_printf("|to%oto|\n", -32);
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
	printf("Test %d : printf(\"|to%%oto|\\n\", 2147483647)\n", i);
	a = printf("|to%oto|\n", 2147483647);
	b = ft_printf("|to%oto|\n", 2147483647);
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
	printf("Test %d : printf(\"|to%%oto|\\n\", 0)\n", i);
	a = printf("|to%oto|\n", 0);
	b = ft_printf("|to%oto|\n", 0);
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
	printf("Test %d : printf(\"|to%%lOto|\\n\", -1L)\n", i);
	a = printf("|to%lOto|\n", -1L);
	b = ft_printf("|to%lOto|\n", -1L);
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
	printf("Test %d : printf(\"|to%%lOto|\\n\", 2147483648L)\n", i);
	a = printf("|to%lOto|\n", 2147483648L);
	b = ft_printf("|to%lOto|\n", 2147483648L);
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
	printf("Test %d : printf(\"|to%%l0to|\\n\", 4200000000000L)\n", i);
	a = printf("|to%lOto|\n", 4200000000000L);
	b = ft_printf("|to%lOto|\n", 4200000000000L);
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
	printf("Test %d : printf(\"|to%%xto|\\n\", 0)\n", i);
	a = printf("|to%xto|\n", 0);
	b = ft_printf("|to%xto|\n", 0);
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
	printf("Test %d : printf(\"|to%%xto|\\n\", 4235478)\n", i);
	a = printf("|to%xto|\n", 4235478);
	b = ft_printf("|to%xto|\n", 4235478);
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
	printf("Test %d : printf(\"|to%%xto|\\n\", -42)\n", i);
	a = printf("|to%xto|\n", -42);
	b = ft_printf("|to%xto|\n", -42);
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
	printf("Test %d : printf(\"|to%%Xto|\\n\", 0)\n", i);
	a = printf("|to%Xto|\n", 0);
	b = ft_printf("|to%Xto|\n", 0);
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
	printf("Test %d : printf(\"|to%%Xto|\\n\", 4235478)\n", i);
	a = printf("|to%Xto|\n", 4235478);
	b = ft_printf("|to%Xto|\n", 4235478);
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
	printf("Test %d : printf(\"|to%%Xto|\\n\", -42)\n", i);
	a = printf("|to%Xto|\n", -42);
	b = ft_printf("|to%Xto|\n", -42);
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




	printf("test : %s\n", "\"%c\", 'a'");
	printf("-->");
	printf("%c", 'a');
	printf("<--\n");
	printf("test : %s\n", "\"%c\", 132");
	printf("-->");
	printf("%c", 132);
	printf("<--\n");
	printf("test : %s\n", "\"%c\", -32");
	printf("-->");
	printf("%c", -32);
	printf("<--\n");
	return (0);
}
