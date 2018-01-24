/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:02:23 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 09:52:15 by bpajot      ###    #+. /#+    ###.fr     */
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
	ret = 0;
	while (*p)
	{
		if (*p != '%')
			ret += ft_putchar_int((unsigned char)*p);
		else
		{
			p++;
			while (*p && *p != '%' && *p != 'd' && *p != 'c' && *p != 'C'
					&& *p != 's' && *p != 'S')
				p++;
			if (*p)
			{
				if (*p == '%')
					ret += ft_putchar_int((unsigned char)*p);
				else if (*p == 'd')
				{
					i = va_arg(ap, int);
					ret += ft_strlen(ft_itoa(i));
					ft_putnbr(i);
				}
				else if (*p == 'c')
				{
					c = va_arg(ap, int);
					ret += ft_putchar_int((unsigned char)c);
				}
				else if (*p == 'C')
				{
					wc = va_arg(ap, int);
					ret += ft_putwchar(wc);
				}
				else if (*p == 's')
				{
					str = va_arg(ap, char*);
					if (str)
						ret += ft_putstr_size(str);
					else
						ret += ft_putstr_size("(null)");
				}
				else if (*p == 'S')
				{
					wstr = va_arg(ap, int*);
					if (wstr)
						ret += ft_putwstr(wstr);
					else
						ret += ft_putstr_size("(null)");
				}
			}
		}
		p++;
	}
	va_end(ap);
	return (ret);
}
