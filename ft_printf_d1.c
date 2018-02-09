/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 15:23:41 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_d_flag(t_field *cur)
{
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
}

void			ft_printf_d_space(t_field *cur)
{
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
}

void			ft_printf_hhd(t_field *cur, va_list *va)
{
	char		hhd;

	hhd = (char)va_arg(*va, int);
	cur->l = (cur->preci == 0 && hhd == 0) ? 0 : ft_nbr_size(hhd);
	ft_printf_d_flag(cur);
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && hhd >= 0)
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (hhd < 0) ? 1 : 0;
	cur->pos = (hhd < 0 && hhd != -128) ? -hhd : hhd;
	if (cur->preci > ft_nbr_size(hhd) - cur->minus)
		cur->zero = cur->preci - ft_nbr_size(hhd) + cur->minus;
	ft_printf_d_space(cur);
	if (cur->preci != 0 || hhd != 0)
		cur->ret += (hhd == -128) ? ft_putstr_size("128") :
			ft_putnbr_size(cur->pos);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
}

void			ft_printf_hd(t_field *cur, va_list *va)
{
	short		hd;

	hd = (short)va_arg(*va, int);
	cur->l = (cur->preci == 0 && hd == 0) ? 0 : ft_nbr_size(hd);
	ft_printf_d_flag(cur);
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && hd >= 0)
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (hd < 0) ? 1 : 0;
	cur->pos = (hd < 0 && hd != -32768) ? -hd : hd;
	if (cur->preci > ft_nbr_size(hd) - cur->minus)
		cur->zero = cur->preci - ft_nbr_size(hd) + cur->minus;
	ft_printf_d_space(cur);
	if (cur->preci != 0 || hd != 0)
		cur->ret += (hd == -32768) ? ft_putstr_size("32768") :
			ft_putnbr_size(cur->pos);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
}

void			ft_printf_d(t_field *cur, va_list *va)
{
	int			d;

	d = va_arg(*va, int);
	cur->l = (cur->preci == 0 && d == 0) ? 0 : ft_nbr_size(d);
	ft_printf_d_flag(cur);
	if (((cur->flag & PLUS) || (cur->flag & SPACE)) && d >= 0)
	{
		cur->plus = (cur->flag & PLUS) ? 1 : 2;
		cur->l++;
	}
	cur->minus = (d < 0) ? 1 : 0;
	cur->pos = (d < 0 && d != -2147483648) ? -d : d;
	if (cur->preci > ft_nbr_size(d) - cur->minus)
		cur->zero = cur->preci - ft_nbr_size(d) + cur->minus;
	ft_printf_d_space(cur);
	if (cur->preci != 0 || d != 0)
		cur->ret += (d == -2147483648) ? ft_putstr_size("2147483648") :
			ft_putnbr_size(cur->pos);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
}
