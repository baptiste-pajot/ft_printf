/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:31:26 by bpajot      ###    #+. /#+    ###.fr     */
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

	printf("setlocale(LC_TYPE, NULL)\n");
	setlocale(LC_ALL, "");
	printf("LC_TYPE = %s\n", setlocale(LC_CTYPE, NULL));
	printf("MB_CUR_MAX = %i\n\n", MB_CUR_MAX);

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

	return (0);
}
