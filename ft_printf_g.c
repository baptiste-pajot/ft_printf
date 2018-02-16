/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_g.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:31:49 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:48:49 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_g(t_field *cur, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (cur)
	{
		c = va_arg(*va, int);
	}
}

void		ft_printf_gg(t_field *cur, va_list *va)
{
	wchar_t		wc;
	int			ret;

	ret = 0;
	if (cur)
	{
		wc = va_arg(*va, int);
	}
}
