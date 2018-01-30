/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 17:25:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
	printf("test : %s\n", "\"%c\", 0");
	printf("-->");
	printf("%c", 0);
	printf("<--\n");
	printf("test : %s\n", "\"%c\", 32");
	printf("-->");
	printf("%c", 32);
	printf("<--\n");
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
