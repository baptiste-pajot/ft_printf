/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_u.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:33:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 11:53:31 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u(t_field *cur, va_list *va)
{
	unsigned int	u;
	int				ret;
	int				len;
	int				spc_bfr;
	int				spc_aft;
	int				zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	u = va_arg(*va, unsigned int);
	if (cur->preci == 0 && u == 0)
		len = 0;
	else
		len = ft_nbr_u_size(u);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->preci > len)
		zero = cur->preci - len;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || u != 0)
		ret += ft_putnbr_u_size(u);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}

int		ft_printf_uu(t_field *cur, va_list *va)
{
	unsigned long int	uu;
	int					ret;
	int					len;
	int					spc_bfr;
	int					spc_aft;
	int					zero;

	ret = 0;
	spc_bfr = 0;
	spc_aft = 0;
	zero = 0;
	uu = va_arg(*va, unsigned long int);
	if (cur->preci == 0 && uu == 0)
		len = 0;
	else
		len = ft_nbr_u_long_size(uu);
	if ((cur->preci >= 0 || (cur->flag & MINUS)) && (cur->flag & ZERO))
		cur->flag -= ZERO;
	if ((cur->flag & PLUS) && (cur->flag & SPACE))
		cur->flag -= SPACE;
	if (cur->preci > len)
		zero = cur->preci - len;
	if (cur->width > len && (cur->flag & ZERO))
		zero = (cur->width - len > zero) ? cur->width - len : zero;
	if (cur->width > len + zero && !(cur->flag & ZERO) && !(cur->flag & MINUS))
		spc_bfr = cur->width - len - zero;
	if (cur->width > len + zero && (cur->flag & MINUS))
		spc_aft = cur->width - len - zero;
	ret += ft_putchar_sizel(' ', spc_bfr);
	ret += ft_putchar_sizel('0', zero);
	if (cur->preci != 0 || uu != 0)
		ret += ft_putnbr_u_long_size(uu);
	ret += ft_putchar_sizel(' ', spc_aft);
	return (ret);
}
