/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 17:06:32 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_f(t_field *cur, va_list *va)
{
	double		f;
	t_double	*d;

	cur->preci = (cur->preci < 0) ? 6 : cur->preci;
	f = va_arg(*va, double);
	d = ft_double_info(f);
	cur->ret += (d->s) ? ft_putchar_size('-') : 0;
	cur->ret += ft_putnbr_double(d, cur->preci);
	ft_memdel((void**)&d);
}

void		ft_printf_lf(t_field *cur, va_list *va)
{
	long double		lf;

	lf = va_arg(*va, long double);
	cur->ret += ft_putnbr_size((int)lf);
}
