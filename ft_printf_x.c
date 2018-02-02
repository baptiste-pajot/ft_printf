/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:34:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 08:49:11 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(t_field *current, va_list *va)
{
	unsigned int		x;
	int					ret;

	ret = 0;
	x = va_arg(*va, unsigned int);
	if (current->flag & SHARP)
		ret+= ft_putstr_size("0x");
	ret += ft_putnbr_base(x, 16, 0);
	return (ret);
}

int		ft_printf_xx(t_field *current, va_list *va)
{
	unsigned int		xx;
	int					ret;

	ret = 0;
	xx = va_arg(*va, unsigned int);
	if (current->flag & SHARP)
		ret+= ft_putstr_size("0X");
	ret += ft_putnbr_base(xx, 16, 1);
	return (ret);
}
