/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_f.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:30:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:48:43 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_f(t_field *cur, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (cur)
	{
		c = va_arg(*va, int);
	}
}

void		ft_printf_ff(t_field *cur, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (cur)
	{
		wc = va_arg(*va, int);
	}
}
