/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:02:23 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 08:30:52 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*p;
	char		*str;
	wchar_t		*wstr;
	char		c;
	wchar_t		wc;
	int			i;
	int			ret;

	ret = ft_strlen(format);
	va_start(ap, format);
	p = (char*)format;
	while (*p)
	{
		if (*p != '%')
			ft_putchar_int((unsigned char)*p);
		else
		{
			p++;
			if (*p == '%')
				ft_putchar_int((unsigned char)*p);
			if (*p == 'd')
			{
				i = va_arg(ap, int);
				ret += ft_strlen(ft_itoa(i)) - 2;
				ft_putnbr(i);
			}
			if (*p == 'c')
			{
				c = va_arg(ap, int);
				ret--;
				ft_putchar_int((unsigned char)c);
			}
			if (*p == 'C')
			{
				wc = va_arg(ap, int);
				ret += ft_putwchar(wc) - 2;
			}
			if (*p == 's')
			{
				str = va_arg(ap, char*);
				ret += ft_strlen(str) - 2;
				ft_putchar_size(str, ft_strlen(str));
			}
			if (*p == 'S')
			{
				wstr = va_arg(ap, int*);
				ret += ft_putwstr(wstr) - 2;
			}
		}
		p++;
	}
	va_end(ap);
	return (ret);
}
