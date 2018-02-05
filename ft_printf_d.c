/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 14:04:05 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_d(t_field *cur, va_list *va)
{
	int			d;
	int			pos;
	int			ret;
	int			len;
	int			plus;
	int			minus;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	minus = 0;
	plus = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	d = va_arg(*va, int);
	if (cur->preci == 0 && d == 0)
		len = 0;
	else
		len = ft_nbr_size(d);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if ((cur->flag & PLUS) && d >= 0)
	{
		plus = 1;
		len++;
	}
	if ((cur->flag & SPACE) && d >= 0)
	{
		plus = 2;
		len++;
	}
	if (d < 0)
		minus = 1;
	if (d < 0 && d != -2147483648)
		pos = -d;
	else
		pos = d;
	if (cur->preci > ft_nbr_size(d) - minus)
		zero = cur->preci - ft_nbr_size(d) + minus;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	if (plus == 1)
		ret += ft_putchar_size('+');
	if (plus == 2)
		ret += ft_putchar_size(' ');
	if (minus == 1)
		ret += ft_putchar_size('-');
	ret += ft_putchar_sizel('0', zero);
	if (d != -2147483648 && (cur->preci != 0 || d != 0))
		ret += ft_putnbr_size(pos);
	else if (d == -2147483648)
		ret += ft_putstr_size("2147483648");
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int			ft_printf_dd(t_field *cur, va_list *va)
{
	long int	dd;
	int			ret;
	long int	pos;
	int			len;
	int			plus;
	int			minus;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	minus = 0;
	plus = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	dd = va_arg(*va,long int);
	if (cur->preci == 0 && dd == 0)
		len = 0;
	else
		len = ft_nbr_long_size(dd);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if ((cur->flag & PLUS) && dd >= 0)
	{
		plus = 1;
		len++;
	}
	if ((cur->flag & SPACE) && dd >= 0)
	{
		plus = 2;
		len++;
	}
	if (dd < 0)
		minus = 1;
	if (dd < 0)
		pos = -dd;
	else
		pos = dd;
	if (cur->preci > ft_nbr_long_size(dd) - minus)
		zero = cur->preci - ft_nbr_long_size(dd) + minus;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	if (plus == 1)
		ret += ft_putchar_size('+');
	if (plus == 2)
		ret += ft_putchar_size(' ');
	if (minus == 1)
		ret += ft_putchar_size('-');
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || dd != 0)
		ret += ft_putnbr_long_size(pos);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
