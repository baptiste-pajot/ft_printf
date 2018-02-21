/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 16:19:43 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_f(t_field *cur, va_list *va)
{
	double		f;

	cur->preci = (cur->preci < 0) ? 6 : cur->preci;
	f = va_arg(*va, double);
	cur->ret += (f > 0.0) ? 0 : ft_putchar_size('-');
	f = (f > 0.0) ? f : -f;
	cur->ret += ft_putnbr_double_int(f);
	cur->ret += (cur->preci == 0) ? 0 : ft_putchar_size('.');
	cur->ret += ft_putchar_sizel('0', cur->preci);
	ft_putendl("");
	ft_putnbr_double_info(f);
}

void		ft_printf_lf(t_field *cur, va_list *va)
{
	long double		lf;

	lf = va_arg(*va, long double);
	cur->ret += ft_putnbr_size((int)lf);
}
