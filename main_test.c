/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:52:31 by bpajot      ###    #+. /#+    ###.fr     */
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
	wchar_t	s[4];

	i = 0;
	a = 0;
	b = 0;
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	printf("\nLC_TYPE = %s\n", setlocale(LC_CTYPE, NULL));
	printf("MB_CUR_MAX = %i\n\n", MB_CUR_MAX);
	i++;
	printf("Test %d : printf(\"|%%9.6ls|\\n\", s)\n", i);
	a = printf("|%9.6ls|\n", s);
	b = ft_printf("||%9.6ls|\n", s);
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
	printf("Test %d : printf(\"|%%9.6ls %%S|\\n\", s, (wchar_t*)'a')\n", i);
	a = printf("|%9.6ls %S|\n", s, (wchar_t *)'a');
	b = ft_printf("|%9.6ls %S|\n", s, (wchar_t*)'a');
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

	printf("setlocale(LC_ALL, \"\")\n");
	setlocale(LC_ALL, "");
	printf("LC_TYPE = %s\n", setlocale(LC_CTYPE, ""));
	printf("MB_CUR_MAX = %i\n\n", MB_CUR_MAX);

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
