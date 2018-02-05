/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:23:18 by bpajot      ###    #+. /#+    ###.fr     */
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




	printf("test : %s\n", "\"%05.5d\", 32");
	printf("-->");
	printf("%05.5d", 32);
	printf("<--\n");
	printf("test : %s\n", "\"%2d\", 4321");
	printf("-->");
	printf("%2d", 4321);
	printf("<--\n");
	return (0);
}
