/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:31:29 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_d(t_field *current, va_list *va)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (current)
	{
		i = va_arg(*va, int);
		ret += ft_putnbr_size(i);
	}
	return (ret);
}

int			ft_printf_D(t_field *current, va_list *va)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (current)
	{
		i = va_arg(*va, int);
//		ret += ft_putnbr_size(i);
	}
	return (ret);
}
