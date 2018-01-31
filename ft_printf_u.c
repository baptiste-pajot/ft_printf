/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_u.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:33:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:48:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u(t_field *current, va_list *va)
{
	char		c;
	int			ret;

	ret = 0;
	if (current)
	{
		c = va_arg(*va, int);
//		ret = ft_putchar_int((unsigned char)c);
	}
	return (ret);
}

int		ft_printf_U(t_field *current, va_list *va)
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
