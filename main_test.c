/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:09:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:33:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//make && gcc -g main_test.c libftprintf.a && valgrind --leak-check=full ./test

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <math.h>

int		main(void)
{
	int		a;
	int		b;
	int		i;
	char	*p = "tata";
	int		int1;
	int		int2;
	char	*p_null = NULL;
	wchar_t	s[4];

	i = 0;
	a = 0;
	b = 0;
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	i++;
	printf("Test %d : printf(\"|%%*d|\\n\", 5, 42)\n", i);
	a = printf("|%*d|\n", 5, 42);
	b = ft_printf("|%*d|\n", 5, 42);
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
	printf("Test %d : printf(\"|%%.*d|\\n\", 5, 42)\n", i);
	a = printf("|%.*d|\n", 5, 42);
	b = ft_printf("|%.*d|\n", 5, 42);
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
	printf("Test %d : printf(\"|%%3*p|\\n\", 10, 0)\n", i);
	a = printf("|%3*p|\n", 10, 0);
	b = ft_printf("|%3*p|\n", 10, 0);
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
	printf("Test %d : printf(\"|%%*3d|\\n\", 0, 10)\n", i);
	a = printf("|%*3d|\n", 0, 10);
	b = ft_printf("|%*3d|\n", 0, 10);
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
	printf("0 preci 0 : |%.0f|\n", 0.0);
	printf("+0 : %.350f\n", 0.0);
	printf("-0 : %.350f\n", (-0.0));
	printf("+Inf : %.1f\n", (3 / 0.0));
	printf("-Inf : %.1f\n", (-3 / 0.0));
	printf("+Inf : %.1F\n", (3 / 0.0));
	printf("-Inf : %.1F\n", (-3 / 0.0));
	printf("NaN : %.1f\n", (0.0 / 0.0));
	ft_putendl("");
	printf("DBL_MANT_DIG : %d\n", DBL_MANT_DIG);
	printf("DBL_MIN_EXP : %d\n", DBL_MIN_EXP);
	printf("DBL_MAX_EXP : %d\n", DBL_MAX_EXP);
	printf("DBL_DIG : %d\n", DBL_DIG);
	printf("DBL_MIN_10_EXP : %d\n", DBL_MIN_10_EXP);
	printf("DBL_MAX_10_EXP : %d\n", DBL_MAX_10_EXP);
	printf("DBL_MIN : %.1025f\n", DBL_MIN);
	printf("DBL_MAX : %f\n", DBL_MAX);
	printf("DBL_EPSILON : %.80f\n", DBL_EPSILON);
	ft_putendl("");
	printf("LDBL_MANT_DIG : %d\n", LDBL_MANT_DIG);
	printf("LDBL_MIN_EXP : %d\n", LDBL_MIN_EXP);
	printf("LDBL_MAX_EXP : %d\n", LDBL_MAX_EXP);
	printf("LDBL_DIG : %d\n", LDBL_DIG);
	printf("LDBL_MIN_10_EXP : %d\n", LDBL_MIN_10_EXP);
	printf("LDBL_MAX_10_EXP : %d\n", LDBL_MAX_10_EXP);
	printf("LDBL_MIN : %.300Lf\n", LDBL_MIN);
	printf("LDBL_MAX : %Lf\n", LDBL_MAX);
	printf("LDBL_EPSILON : %.80Lf\n", LDBL_EPSILON);
	ft_putendl("");
	printf("CHAR_MIN : %d\n", CHAR_MIN);
	printf("CHAR_MAX : %d\n", CHAR_MAX);
	printf("UCHAR_MAX : %d\n", UCHAR_MAX);
	printf("SHRT_MIN : %d\n", SHRT_MIN);
	printf("SHRT_MAX : %d\n", SHRT_MAX);
	printf("USHRT_MAX : %d\n", USHRT_MAX);
	printf("INT_MIN : %d\n", INT_MIN);
	printf("INT_MAX : %d\n", INT_MAX);
	printf("UINT_MAX : %u\n", UINT_MAX);
	printf("SIZE_MAX : %llu\n", SIZE_MAX);
	printf("LONG_MIN : %ld\n", LONG_MIN);
	printf("LONG_MAX : %ld\n", LONG_MAX);
	printf("ULONG_MAX : %lu\n", ULONG_MAX);
	printf("LLONG_MIN : %lld\n", LLONG_MIN);
	printf("LLONG_MAX : %lld\n", LLONG_MAX);
	printf("ULLONG_MAX : %llu\n", ULLONG_MAX);
	printf("INTMAX_MIN : %lld\n", INTMAX_MIN);
	printf("INTMAX_MAX : %lld\n", INTMAX_MAX);
	printf("UINTMAX_MIN : %llu\n", UINTMAX_MAX);
	printf("WCHAR_MIN : %d\n", WCHAR_MIN);
	printf("WCHAR_MAX : %d\n", WCHAR_MAX);
	printf("WINT_MIN : %d\n", WINT_MIN);
	printf("WINT_MAX : %d\n", WINT_MAX);
	p = ft_sum("0", "0", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("3", "9", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("23", "8", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("9", "101", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	ft_putendl("");
	p = ft_sum("0.0", "0.0", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("0.3", "0.9", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("0.23", "0.8", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("0.9", "0.101", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	ft_putendl("");
	p = ft_sum("1.0", "0.0", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("2.3", "1.9", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("101.23", "0.0844445", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_sum("415650.95660005", "1005115151615100.00000414141101", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	ft_putendl("");
	p = ft_round("1", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_round("1.4", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_round("1.5", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_round("2.3", 3);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_round("101.2345641616888183", 10);
	ft_putendl(p);
	ft_memdel((void**)&p);
	p = ft_round("415650.95660005", 0);
	ft_putendl(p);
	ft_memdel((void**)&p);
	ft_putendl("");
	ft_putendl("0000");
	ft_putnbr(ft_get_exponent("0000"));
	ft_putendl("");
	ft_putendl("0123");
	ft_putnbr(ft_get_exponent("0123"));
	ft_putendl("");
	ft_putendl("0123.12345000");
	ft_putnbr(ft_get_exponent("0123.12345000"));
	ft_putendl("");
	ft_putendl("000.000123");
	ft_putnbr(ft_get_exponent("0000.0001223"));
	ft_putendl("");
	ft_putendl("0000.000");
	ft_putnbr(ft_get_exponent("0000.000"));
	ft_putendl("");
	ft_putendl("1.000");
	ft_putnbr(ft_get_exponent("1.000"));
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%0100.70e|\\n\", 1.15)\n", i);
	a = printf("|%0100.70e|\n", 1.15);
	b = ft_printf("|%0100.70e|\n", 1.15);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return vralue NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%0100.70E|\\n\", 1.15)\n", i);
	a = printf("|%0100.70E|\n", 1.15);
	b = ft_printf("|%0100.70E|\n", 1.15);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return vralue NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%0100.70f|\\n\", 1.15)\n", i);
	a = printf("|%0100.70f|\n", 1.15);
	b = ft_printf("|%0100.70f|\n", 1.15);
	ft_putstr("return value printf : ");
	ft_putnbr(a);
	ft_putendl("");
	ft_putstr("return value ft_printf : ");
	ft_putnbr(b);
	ft_putendl("");
	if (a == b)
		printf("Test %d : return value OK\n", i);
	else
		printf("Test %d : return vralue NOK !!!\n", i);
	ft_putendl("");
	i++;
	printf("Test %d : printf(\"|%%20.0e|\\n\", -1024.0)\n", i);
	a = printf("|%20.0e|\n", -1024.0);
	b = ft_printf("|%20.0e|\n", -1024.0);
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
	printf("Test %d : printf(\"|%%20.1025e|\\n\", -0.0)\n", i);
	a = printf("|%20.1025e|\n", -(0.0));
	b = ft_printf("|%20.1025e|\n", -(0.0));
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
	printf("Test %d : printf(\"|%%20.42le|\\n\", 1444565444646.6465424242242)\n", i);
	a = printf("|%20.42le|\n", 1444565444646.6465424242242);
	b = ft_printf("|%20.42le|\n", 1444565444646.6465424242242);
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
	printf("Test %d : printf(\"|%%e|\\n\", -148681115151511651115156115115.428168111651151616161566156)\n", i);
	a = printf("|%e|\n", -148681115151511651115156115115.428168111651151616161566156);
	b = ft_printf("|%e|\n", (-148681115151511651115156115115.428168111651151616161566156));
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
	printf("Test %d : printf(\"|%%e|\\n\", 1234567890123456789012345678901234567890)\n", i);
	a = printf("|%e|\n", 1234567890123456789012345678901234567890.123);
	b = ft_printf("|%e|\n", 1234567890123456789012345678901234567890.123);
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
	printf("Test %d : printf(\"|%%.80e|\\n\", -0.00000000000000000000000000000000000000000001)\n", i);
	a = printf("|%.80e|\n", -0.00000000000000000000000000000000000000000001);
	b = ft_printf("|%.80e|\n", -0.00000000000000000000000000000000000000000001);
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
	printf("Test %d : printf(\"|%%.10e|\\n\", -0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001732)\n", i);
	a = printf("|%.315e|\n", -0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001732);
	b = ft_printf("|%.315e|\n", -0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001732);
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
	printf("Test %d : printf(\"|%%.2e|\\n\", -0.00099999)\n", i);
	a = printf("|%.2e|\n", -0.00099999);
	b = ft_printf("|%.2e|\n", -0.00099999);
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
	printf("Test %d : printf(\"|%%48.30le|\\n\", 1569447846)\n", i);
	a = printf("|%48.30e|\n", 1569447846.0);
	b = ft_printf("|%48.30e|\n", 1569447846.0);
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
	printf("Test %d : printf(\"|%%.3e|\\n\", 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0)\n", i);
	a = printf("|%.3e|\n", 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0);
	b = ft_printf("|%.3e|\n", 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0);
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
	printf("Test %d : printf(\"|%%51.59e|\\n\", (0.0/0.0))\n", i);
	a = printf("|%51.59e|\n", (0.0/0.0));
	b = ft_printf("|%51.59e|\n", (0.0/0.0));
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
	printf("Test %d : printf(\"|%%051.59e|\\n\", (0.0/0.0))\n", i);
	a = printf("|%051.59e|\n", (0.0/0.0));
	b = ft_printf("|%051.59e|\n", (0.0/0.0));
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
	printf("Test %d : printf(\"|%%e|\\n\", 1.42)\n", i);
	a = printf("|%e|\n", 1.42);
	b = ft_printf("|%e|\n", 1.42);
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
	printf("Test %d : printf(\"|%%02.32e|\\n\", 40518.36752852692734450101852416992187)\n", i);
	a = printf("|%02.32e|\n", 40518.36752852692734450101852416992187);
	b = ft_printf("|%02.32e|\n", 40518.36752852692734450101852416992187);
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
	printf("Test %d : printf(\"|%%02.35e|\\n\", 40518.36752852692734450101852416992187)\n", i);
	a = printf("|%02.35e|\n", 40518.36752852692734450101852416992187);
	b = ft_printf("|%02.35e|\n", 40518.36752852692734450101852416992187);
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
	printf("Test %d : printf(\"|%%.32e|\\n\", 43368.58690757967997342348098754882813)\n", i);
	a = printf("|%.32e|\n", 43368.58690757967997342348098754882813);
	b = ft_printf("|%.32e|\n", 43368.58690757967997342348098754882813);
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
	printf("Test %d : printf(\"|%%.38e|\\n\", 43368.58690757967997342348098754882813)\n", i);
	a = printf("|%.38e|\n", 43368.58690757967997342348098754882813);
	b = ft_printf("|%.38e|\n", 43368.58690757967997342348098754882813);
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
	printf("Test %d : printf(\"|%%.1e|\\n\", (3.0/0.0))\n", i);
	a = printf("|%.1e|\n", (3.0/0.0));
	b = ft_printf("|%.1e|\n", (3.0/0.0));
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
	printf("Test %d : printf(\"|%%.1E|\\n\", (3.0/0.0))\n", i);
	a = printf("|%.1E|\n", (3.0/0.0));
	b = ft_printf("|%.1E|\n", (3.0/0.0));
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
	printf("Test %d : printf(\"|%%.0LE|\\n\", 0.0L)\n", i);
	a = printf("|%.0LE|\n", 0.0L);
	b = ft_printf("|%.0LE|\n", 0.0L);
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
	printf("Test %d : printf(\"|%%.0Le|\\n\", -1023.0L)\n", i);
	a = printf("|%.0Le|\n", -1023.0L);
	b = ft_printf("|%.0Le|\n", -1023.0L);
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
	printf("Test %d : printf(\"|%%Le|\\n\", 1.4L)\n", i);
	a = printf("|%.30Le|\n", 1.4L);
	b = ft_printf("|%.30Le|\n", 1.4L);
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
	printf("Test %d : printf(\"|%%Le|\\n\", -1.4L)\n", i);
	a = printf("|%Le|\n", -1.4L);
	b = ft_printf("|%Le|\n", -1.4L);
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
	printf("Test %d : printf(\"|%%Lg|\\n\", -1.4L)\n", i);
	a = printf("|%Lg|\n", -1.4L);
	b = ft_printf("|%Lg|\n", -1.4L);
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
	printf("Test %d : printf(\"|%%.2g|\\n\", -1.41L)\n", i);
	a = printf("|%.2g|\n", -1.41);
	b = ft_printf("|%.2g|\n", -1.41);
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
	printf("Test %d : printf(\"|%%20.10G|\\n\", -141616181811111.0)\n", i);
	a = printf("|%20.10G|\n", -141616181811111.0);
	b = ft_printf("|%20.10G|\n", -141616181811111.0);
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
	printf("Test %d : printf(\"|%%g|\\n\", 0.0)\n", i);
	a = printf("|%g|\n", 0.0);
	b = ft_printf("|%g|\n", 0.0);
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
	printf("Test %d : printf(\"|%%20.10g|\\n\", 0.0)\n", i);
	a = printf("|%20.10g|\n", 0.0);
	b = ft_printf("|%20.10g|\n", 0.0);
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
	printf("Test %d : printf(\"|%%20.10Lg|\\n\", 0.0L)\n", i);
	a = printf("|%20.10Lg|\n", 0.0L);
	b = ft_printf("|%20.10Lg|\n", 0.0L);
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
	printf("Test %d : printf(\"|%%.2g|\\n\", 42.2)\n", i);
	a = printf("|%.2g|\n", 42.2);
	b = ft_printf("|%.2g|\n", 42.2);
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
	printf("Test %d : printf(\"|%%.4g|\\n\", 421.231)\n", i);
	a = printf("|%.4g|\n", 421.231);
	b = ft_printf("|%.4g|\n", 421.231);
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
	printf("Test %d : printf(\"|%%.10g|\\n\", 42.2)\n", i);
	a = printf("|%.10g|\n", 42.2);
	b = ft_printf("|%.10g|\n", 42.2);
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
	printf("Test %d : printf(\"|%%g|\\n\", -8000.0)\n", i);
	a = printf("|%g|\n", -8000.0);
	b = ft_printf("|%g|\n", -8000.0);
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
	printf("Test %d : printf(\"|abc%%n|\\n\", p)\n", i);
	a = printf("|abc%n|\n", &int1);
	printf("%d\n", int1);
	b = ft_printf("|abc%n|\n", &int2);
	ft_printf("%d\n", int2);
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
