/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_o.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:32:07 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_field *cur, va_list *va)
{
	unsigned int	o;

	o = va_arg(*va, unsigned int);
	cur->l = (cur->preci == 0 && o == 0) ? 0 : ft_nbr_size_base(o, 8);
	cur->l += (cur->flag & SHARP && o) ? 1 : 0;
	cur->zero = (cur->preci > cur->l) ? cur->preci - cur->l : 0;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->width > cur->l && (cur->flag & ZERO))
		cur->zero = (cur->width - cur->l > cur->zero) ? cur->width - cur->l :
			cur->zero;
	if (cur->width > cur->l + cur->zero && !(cur->flag & ZERO) && !(cur->flag &
		MINUS))
		cur->spc_bfr = cur->width - cur->l - cur->zero;
	if (cur->width > cur->l + cur->zero && (cur->flag & MINUS))
		cur->spc_aft = cur->width - cur->l - cur->zero;
	cur->ret += ft_putchar_sizel(' ', cur->spc_bfr);
	cur->ret += ft_putchar_sizel('0', cur->zero);
	cur->ret += (cur->flag & SHARP) ? ft_putchar_size('0') : 0;
	if ((!(cur->flag & SHARP) || o) && (cur->preci || o))
		cur->ret += ft_putnbr_base(o, 8, 0);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}

int		ft_printf_oo(t_field *cur, va_list *va)
{
	unsigned long	oo;

	oo = va_arg(*va, unsigned long);
	cur->l = (cur->preci == 0 && oo == 0) ? 0 : ft_nbr_long_size_base(oo, 8);
	cur->l += (cur->flag & SHARP && oo) ? 1 : 0;
	cur->zero = (cur->preci > cur->l) ? cur->preci - cur->l : 0;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->width > cur->l && (cur->flag & ZERO))
		cur->zero = (cur->width - cur->l > cur->zero) ? cur->width - cur->l :
			cur->zero;
	if (cur->width > cur->l + cur->zero && !(cur->flag & ZERO) && !(cur->flag &
		MINUS))
		cur->spc_bfr = cur->width - cur->l - cur->zero;
	if (cur->width > cur->l + cur->zero && (cur->flag & MINUS))
		cur->spc_aft = cur->width - cur->l - cur->zero;
	cur->ret += ft_putchar_sizel(' ', cur->spc_bfr);
	cur->ret += ft_putchar_sizel('0', cur->zero);
	cur->ret += (cur->flag & SHARP) ? ft_putchar_size('0') : 0;
	if ((!(cur->flag & SHARP) || oo) && (cur->preci || oo))
		cur->ret += ft_putnbr_long_base(oo, 8, 0);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}
