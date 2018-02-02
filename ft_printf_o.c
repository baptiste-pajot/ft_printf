/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_o.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 12:23:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_field *current, va_list *va)
{
	unsigned int	o;
	int				ret;

	ret = 0;
	o = va_arg(*va, unsigned int);
	if (current->flag & SHARP)
		ret += ft_putchar_size('0');
	ret += ft_putnbr_base(o, 8, 0);
	return (ret);
}

int		ft_printf_oo(t_field *current, va_list *va)
{
	unsigned long	oo;
	int				ret;

	ret = 0;
	oo = va_arg(*va, unsigned long);
	if (current->flag & SHARP)
		ret += ft_putchar_size('0');
	ret += ft_putnbr_long_base(oo, 8, 0);
	return (ret);
}
