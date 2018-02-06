/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:15:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 14:21:18 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(t_field *cur, va_list *va)
{
	char		c;
	int			ret;
	int			len;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	c = va_arg(*va, int);
	if (cur->preci == 0 && c == 0)
		len = 0;
	else
		len = 1;
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
	if (cur->preci != 0 || c != 0)
		ret += ft_putchar_size(c);
	else
		ret++;
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int		ft_printf_cc(t_field *cur, va_list *va)
{
	wchar_t		wc;
	int			ret;
	int			len;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	wc = va_arg(*va, int);
	if (cur->preci == 0 && wc == 0)
		len = 0;
	else
		len = 1;
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
	if (cur->preci != 0 || wc != 0)
		ret += ft_putwchar(wc);
	else
		ret++;
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
