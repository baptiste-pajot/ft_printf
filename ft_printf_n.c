/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_n.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:32:13 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:32:36 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_n(t_field *current, va_list *va)
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
