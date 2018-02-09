/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:34:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:02:32 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(t_field *cur, va_list *va)
{
	unsigned int	x;

	x = va_arg(*va, unsigned int);
	cur->l = (cur->preci == 0 && x == 0) ? 0 : ft_nbr_size_base(x, 16);
	cur->l += ((cur->flag & SHARP) && x) ? 2 : 0;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->preci > cur->l - 2 && (cur->flag & SHARP) && x)
		cur->zero = cur->preci - cur->l + 2;
	if (cur->preci > cur->l && !((cur->flag & SHARP) && x))
		cur->zero = cur->preci - cur->l;
	if (cur->width > cur->l && (cur->flag & ZERO))
		cur->zero = (cur->width - cur->l > cur->zero) ? cur->width - cur->l :
			cur->zero;
	if (cur->width > cur->l + cur->zero && !(cur->flag & ZERO) &&
		!(cur->flag & MINUS))
		cur->spc_bfr = cur->width - cur->l - cur->zero;
	if (cur->width > cur->l + cur->zero && (cur->flag & MINUS))
		cur->spc_aft = cur->width - cur->l - cur->zero;
	cur->ret += ft_putchar_sizel(' ', cur->spc_bfr);
	cur->ret += (cur->flag & SHARP && x) ? ft_putstr_size("0x") : 0;
	cur->ret += ft_putchar_sizel('0', cur->zero);
	cur->ret += (cur->preci != 0 || x) ? ft_putnbr_base(x, 16, 0) : 0;
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}

int		ft_printf_xx(t_field *cur, va_list *va)
{
	unsigned int	xx;

	xx = va_arg(*va, unsigned int);
	cur->l = (cur->preci == 0 && xx == 0) ? 0 : ft_nbr_long_size_base(xx, 16);
	cur->l += ((cur->flag & SHARP) && xx) ? 2 : 0;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->preci > cur->l - 2 && (cur->flag & SHARP) && xx)
		cur->zero = cur->preci - cur->l + 2;
	if (cur->preci > cur->l && !((cur->flag & SHARP) && xx))
		cur->zero = cur->preci - cur->l;
	if (cur->width > cur->l && (cur->flag & ZERO))
		cur->zero = (cur->width - cur->l > cur->zero) ? cur->width - cur->l :
			cur->zero;
	if (cur->width > cur->l + cur->zero && !(cur->flag & cur->zero) &&
		!(cur->flag & MINUS))
		cur->spc_bfr = cur->width - cur->l - cur->zero;
	if (cur->width > cur->l + cur->zero && (cur->flag & MINUS))
		cur->spc_aft = cur->width - cur->l - cur->zero;
	cur->ret += ft_putchar_sizel(' ', cur->spc_bfr);
	cur->ret += (cur->flag & SHARP && xx) ? ft_putstr_size("0X") : 0;
	cur->ret += ft_putchar_sizel('0', cur->zero);
	cur->ret += (cur->preci != 0 || xx) ? ft_putnbr_base(xx, 16, 1) : 0;
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}
