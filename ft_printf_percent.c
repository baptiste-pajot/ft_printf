/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_percent.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:12:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:56:48 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_percent(t_field *cur)
{
	int			ret;
	int			spc_bfr;
	int			spc_aft;
	int			zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->width > 1 && (cur->flag & ZERO))
		zero = cur->width - 1;
	if (cur->width > 1 + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - 1 - zero;
	if (cur->width > 1 + zero && (cur->flag & MINUS))
		spc_aft = cur->width - 1 - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putchar_sizel('0', zero);
	ret += ft_putchar_size('%');
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
