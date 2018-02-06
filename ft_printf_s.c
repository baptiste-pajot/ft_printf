/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_s.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:26:36 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 19:14:05 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(t_field *cur, va_list *va)
{
	char		*str;
	int			ret;
	int			len;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	str = va_arg(*va, char*);
	if (str == 0)
		len = 6;
	else
		len = ft_strlen(str);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if (cur->preci >= 0 && len > cur->preci)
		len = cur->preci;
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
	if (str)
		ret += ft_putstr_sizel(str, len);
	else
		ret += ft_putstr_sizel("(null)", len);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int		ft_printf_ss(t_field *cur, va_list *va)
{
	wchar_t		*wstr;
	int			ret;
	int			len;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	wstr = va_arg(*va, int*);
	if (wstr == 0)
		len = 6;
	else
		len = ft_wstrlen(wstr);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if (cur->preci >= 0 && len > cur->preci)
	{
		len = cur->preci;
		len = ft_wstrlenl(wstr, len);
	}
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
	if (wstr)
		ret += ft_putwstrl(wstr, len);
	else
		ret += ft_putstr_sizel("(null)", len);
	ret += ft_putchar_sizel(' ', spc_aft);
//	ft_putnbr(len);
	return (ret);
}
