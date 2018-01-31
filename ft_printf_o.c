/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_o.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 17:32:39 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(t_field *current, va_list *va)
{
	int			i;
	int			o;
	int			ret;

	ret = 0;
	i = 0;
	o = 0;
	if (current)
	{
		i = va_arg(*va, int);
		ret += ft_putnbr_base(i, 8);
	}
	return (ret);
}

int		ft_printf_O(t_field *current, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (current)
	{
		wc = va_arg(*va, int);
//		ret = ft_putwchar(wc);
	}
	return (ret);
}

