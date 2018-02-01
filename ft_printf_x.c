/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:34:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 17:15:33 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(t_field *current, va_list *va)
{
	unsigned int		x;
	int					ret;

	ret = 0;
	x = 0;
	if (current)
	{
		x = va_arg(*va, unsigned int);
		ret += ft_putnbr_base(x, 16, 0);
	}
	return (ret);
}

int		ft_printf_xx(t_field *current, va_list *va)
{
	unsigned int		xx;
	int					ret;

	ret = 0;
	xx = 0;
	if (current)
	{
		xx = va_arg(*va, unsigned int);
		ret += ft_putnbr_base(xx, 16, 1);
	}
	return (ret);
}
