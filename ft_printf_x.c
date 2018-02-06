/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:34:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 15:01:44 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(t_field *cur, va_list *va)
{
	unsigned int	x;
	int				ret;
	int				len;
	int				spc_bfr;
	int				spc_aft;
	int				zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	x = va_arg(*va, unsigned int);
	if (cur->preci == 0 && x == 0)
		len = 0;
	else
		len = ft_nbr_size_base(x, 16);
	if (cur->flag & SHARP)
		len += 2;
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
	if (cur->flag & SHARP && x)
		ret += ft_putstr_size("0x");
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || x)
		ret += ft_putnbr_base(x, 16, 0);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int		ft_printf_xx(t_field *cur, va_list *va)
{
	unsigned int	xx;
	int				ret;
	int				len;
	int				spc_bfr;
	int				spc_aft;
	int				zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	xx = va_arg(*va, unsigned int);
	if (cur->preci == 0 && xx == 0)
		len = 0;
	else
		len = ft_nbr_long_size_base(xx, 16L);
	if (cur->flag & SHARP)
		len += 2;
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
	if (cur->flag & SHARP && xx)
		ret += ft_putstr_size("0X");
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || xx)
		ret += ft_putnbr_base(xx, 16, 1);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
