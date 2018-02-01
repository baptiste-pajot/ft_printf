/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_s.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:26:36 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 17:12:20 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(t_field *current, va_list *va)
{
	char		*str;
	int			ret;

	ret = 0;
	if (current)
	{
		str = va_arg(*va, char*);
		if (str)
			ret += ft_putstr_size(str);
		else
			ret += ft_putstr_size("(null)");
	}
	return (ret);
}

int		ft_printf_ss(t_field *current, va_list *va)
{
	wchar_t		*wstr;
	int			ret;

	ret = 0;
	if (current)
	{
		wstr = va_arg(*va, int*);
		if (wstr)
			ret += ft_putwstr(wstr);
		else
			ret += ft_putstr_size("(null)");
	}
	return (ret);
}
