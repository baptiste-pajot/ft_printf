/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 14:53:11 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_d(t_field *cur, va_list *va)
{
	int			d;

	d = va_arg(*va, int);
	cur->l = (cur->preci == 0 && d == 0) ? 0 : ft_nbr_size(d);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && d >= 0)
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (d < 0) ? 1 : 0;
	cur->pos = (d < 0 && d != -2147483648) ? -d : d;
	if (cur->preci > ft_nbr_size(d) - cur->minus)
		cur->zero = cur->preci - ft_nbr_size(d) + cur->minus;
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
	if (cur->preci != 0 || d != 0)
		cur->ret += (d == -2147483648) ? ft_putstr_size("2147483648") :
			ft_putnbr_size(cur->pos);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}

int			ft_printf_dd(t_field *cur, va_list *va)
{
	long int	dd;

	dd = va_arg(*va, long int);
	cur->l = (cur->preci == 0 && dd == 0) ? 0 : ft_nbr_long_size(dd);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && dd >= 0)
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (dd < 0) ? 1 : 0;
	cur->pos_long = (dd < 0 && dd != LONG_MIN) ? -dd : dd;
	if (cur->preci > ft_nbr_long_size(dd) - cur->minus)
		cur->zero = cur->preci - ft_nbr_long_size(dd) + cur->minus;
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
	if (cur->preci != 0 || dd != 0)
		cur->ret += (dd == LONG_MIN ) ? ft_putstr_size("9223372036854775808") :
			ft_putnbr_long_size(cur->pos_long);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}
