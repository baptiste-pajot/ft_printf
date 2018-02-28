/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:05:42 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_f(t_field *cur, va_list *va)
{
	double		f;
	t_double	*d;

	f = va_arg(*va, double);
	d = ft_double_info(f);
	cur->preci = (cur->preci < 0) ? 6 : cur->preci;
	cur->l = ft_doublelen(d, cur->preci);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && !(d->s))
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (d->s && !(d->e == 1024 && d->m)) ? 1 : 0;
	cur->l += (d->s && !(d->e == 1024 && d->m)) ? 1 : 0;
	if (cur->width > cur->l && (cur->flag & ZERO))
		cur->zero = (cur->width - cur->l > cur->zero) ? cur->width - cur->l :
		cur->zero;
	if (cur->width > cur->l + cur->zero && !(cur->flag & ZERO) && !(cur->flag &
		MINUS))
		cur->spc_bfr = cur->width - cur->l - cur->zero;
	if (cur->width > cur->l + cur->zero && (cur->flag & MINUS))
		cur->spc_aft = cur->width - cur->l - cur->zero;
	cur->ret += ft_putchar_sizel(' ', cur->spc_bfr);
	cur->ret += (cur->plus == 1) ? ft_putchar_size('+') : 0;
	cur->ret += (cur->plus == 2) ? ft_putchar_size(' ') : 0;
	cur->ret += (cur->minus == 1) ? ft_putchar_size('-') : 0;
	cur->ret += ft_putchar_sizel('0', cur->zero);
	cur->ret += ft_putnbr_double(d, cur->preci);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	ft_memdel((void**)&d);
}

void		ft_printf_lf(t_field *cur, va_list *va)
{
	long double		lf;

	lf = va_arg(*va, long double);
	cur->ret += ft_putnbr_size((int)lf);
}
