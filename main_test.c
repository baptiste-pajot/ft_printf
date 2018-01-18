/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 17:50:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <stdio.h>
# include "ft_printf.h"
# include <locale.h>

int		main(void)
{
	int		a;
	int		b;
	int		i;

	i = 0;
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
	printf("Test %d : printf(\"|to%%dto|\\n\", 323)\n", i);
	a = printf("|to%dto|\n", 323);
	b = ft_printf("|to%dto|\n", 323);
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
	printf("Test %d : printf(\"|to%%sto|\\n\", \"z123a\")\n", i);
	a = printf("|to%sto|\n", "z123a");
	b = ft_printf("|to%sto|\n", "z123a");
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
	setlocale(LC_ALL, "");
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
	setlocale(LC_ALL, "");
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
	return (0);
}
