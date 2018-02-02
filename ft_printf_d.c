/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 08:47:54 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_d(t_field *current, va_list *va)
{
	int			d;
	int			ret;

	ret = 0;
	d = va_arg(*va, int);
	if ((current->flag & PLUS) && d >= 0)
		ret+= ft_putchar_size('+');
	if ((current->flag & SPACE) && !(current->flag & PLUS) && d >= 0)
		ret+= ft_putchar_size(' ');
	ret += ft_putnbr_size(d);
	return (ret);
}

int			ft_printf_dd(t_field *current, va_list *va)
{
	long int	dd;
	int			ret;

	dd = 0L;
	ret = 0;
	if (current)
	{
		dd = va_arg(*va, long int);
		ret += ft_putnbr_long_size(dd);
	}
	return (ret);
}
