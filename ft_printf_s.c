/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_s.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:26:36 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 17:17:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(t_field *cur, va_list *va)
{
	char		*str;

	str = va_arg(*va, char*);
	cur->l = (str == 0) ? 6 : ft_strlen(str);
	if ((cur->flag & MINUS) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if (cur->preci >= 0 && cur->l > cur->preci)
		cur->l = cur->preci;
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
	cur->ret += (str) ? ft_putstr_sizel(str, cur->l) : ft_putstr_sizel("(null)",
		cur->l);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}

int		ft_printf_ss(t_field *cur, va_list *va)
{
	wchar_t		*wstr;

	wstr = va_arg(*va, int*);
	cur->l = (wstr == 0) ? 6 : ft_wstrlen(wstr);
	if ((cur->flag & MINUS) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if (cur->preci >= 0 && cur->l > cur->preci)
	{
		cur->l = cur->preci;
		cur->l = ft_wstrlenl(wstr, cur->l);
	}
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
	cur->ret += (wstr) ? ft_putwstrl(wstr, cur->l) : ft_putstr_sizel("(null)", 
		cur->l);
	cur->ret += ft_putchar_sizel(' ', cur->spc_aft);
	return (cur->ret);
}
