/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:06:56 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_f(t_field *cur, va_list *va)
{
	double		f;
	long int	f_int;
	double		f_dec;

	f = va_arg(*va, double);
	f_int = (long int)f;
	f_dec = f - (double)f_int;
	f_dec = (f_dec < 0) ? - f_dec : f_dec;
	f_dec += DBL_EPSILON;
	cur->ret += ft_putnbr_long_size(f_int);
	cur->ret += ft_putchar_size('.');
	cur->ret += ft_putnbr_long_size((long int)(f_dec * 1000000));
}

void		ft_printf_lf(t_field *cur, va_list *va)
{
	long double		lf;

	lf = va_arg(*va, long double);
	cur->ret += ft_putnbr_size((int)lf);
}
