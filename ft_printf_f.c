/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 11:56:37 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_f(t_field *current, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (current)
	{
		c = va_arg(*va, int);
	}
	return (ret);
}

int		ft_printf_ff(t_field *current, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (current)
	{
		wc = va_arg(*va, int);
	}
	return (ret);
}
