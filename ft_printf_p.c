/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_p.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:33:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 15:28:31 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_p(t_field *cur, va_list *va)
{
	unsigned long int	p;
	int					ret;
	int					len;
	int					spc_bfr;
	int					spc_aft;
	int					zero;

	ret = 0;
	p =  0L;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	p = va_arg(*va, unsigned long int);
	len = ft_nbr_long_size_base(p, 16);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->preci > len)
		zero = cur->preci - len;
	if (cur->width > len + 2 && (cur->flag & ZERO))
		zero = (cur->width - len - 2 > zero) ? cur->width - len - 2 : zero;
	if (cur->width > len + 2 + zero && !(cur->flag & ZERO) &&
		!(cur->flag & MINUS))
		spc_bfr = cur->width - len - 2 - zero;
	if (cur->width > len - 2 + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - 2 - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putstr_size("0x");
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || p)
		ret += ft_putnbr_long_base(p, 16, 0);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
