/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_o.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:52:13 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_field *cur, va_list *va)
{
	unsigned int	o;
	int				ret;
	int				len;
	int				spc_bfr;
	int				spc_aft;
	int				zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	o = va_arg(*va, unsigned int);
	if (cur->preci == 0 && o == 0)
		len = 0;
	else
		len = ft_nbr_size(o);
	if (cur->flag & SHARP)
		len++;
	if (cur->preci > len)
		zero = cur->preci - len;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putchar_sizel('0', zero);
	if (cur->flag & SHARP)
		ret += ft_putchar_size('0');
	if ((!(cur->flag & SHARP) || o) && (cur->preci || o))
		ret += ft_putnbr_base(o, 8, 0);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int		ft_printf_oo(t_field *cur, va_list *va)
{
	unsigned long	oo;
	int				ret;
	int				len;
	int				spc_bfr;
	int				spc_aft;
	int				zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	oo = va_arg(*va, unsigned long);
	if (cur->preci == 0 && oo == 0)
		len = 0;
	else
		len = ft_nbr_size(oo);
	if (cur->flag & SHARP)
		len++;
	if (cur->preci > len)
		zero = cur->preci - len;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putchar_sizel('0', zero);
	if (cur->flag & SHARP)
		ret += ft_putchar_size('0');
	if ((!(cur->flag & SHARP) || oo) && (cur->preci || oo))
		ret += ft_putnbr_long_base(oo, 8, 0);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
