/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_o.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 17:16:34 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_field *current, va_list *va)
{
	unsigned int	o;
	int				ret;

	ret = 0;
	o = 0;
	if (current)
	{
		o = va_arg(*va, unsigned int);
		ret += ft_putnbr_base(o, 8, 0);
	}
	return (ret);
}

int		ft_printf_oo(t_field *current, va_list *va)
{
	unsigned long	oo;
	int				ret;

	ret = 0;
	oo = 0L;
	if (current)
	{
		oo = va_arg(*va, unsigned long);
		ret += ft_putnbr_long_base(oo, 8, 0);
	}
	return (ret);
}
