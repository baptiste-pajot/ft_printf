/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 10:37:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 17:12:20 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		clean(t_field *field)
{
	t_field		*current;
	t_field		*next;

	current = field;
	while (current)
	{
		next = current->next;
		ft_memdel((void**)&current);
		current = next;
	}
	return (0);
}

static int		ft_printf2(t_field *current, va_list *va)
{
	char		*p;
	char		*str;
	wchar_t		*wstr;
	char		c;
	wchar_t		wc;
	int			i;
	int			ret;

	p = NULL;
	ret = 0;
	if (current->type & PERCENT)
		ret += ft_putchar_int('%');
	if (current->type & D_MIN)
	{
		i = va_arg(*va, int);
		ret += ft_strlen(ft_itoa(i));
		ft_putnbr(i);
	}
	if (current->type & C_MIN)
	{
		c = va_arg(*va, int);
		ret += ft_putchar_int((unsigned char)c);
	}
	if (current->type & C_MAJ)
	{
		wc = va_arg(*va, int);
		ret += ft_putwchar(wc);
	}
	if (current->type & S_MIN)
	{
		str = va_arg(*va, char*);
		if (str)
			ret += ft_putstr_size(str);
		else
			ret += ft_putstr_size("(null)");
	}
	if (current->type & S_MAJ)
	{
		wstr = va_arg(*va, int*);
		if (wstr)
			ret += ft_putwstr(wstr);
		else
			ret += ft_putstr_size("(null)");
	}
	return (ret);
}


int				ft_printf(const char *format, ...)
{
	t_field		*field;
	t_field		*current;
	int			i;
	int			ret;
	va_list		va;

	i = -1;
	ret = 0;
	va_start(va, format);
	field = ft_parse(format);
	current = field;
	if (field == NULL)
		ret += ft_putstr_size((char*)format);
	else
	{
		while (format[++i])
		{
			if (format[i] == '%')
			{
				ret += ft_printf2(current, &va);
				i += current->len;
				current = current->next;
			}
			else
			{
				if (current)
				{
					ret += ft_putstr_size((char*)ft_strsub(format, i,
							current->text - i + 1));
					i += current->text - i;
				}
				else
				{
					ret += ft_putstr_size((char*)&format[i]);
					i += ft_strlen(&format[i]);
				}
			}
		}
	}
	clean(field);
	va_end(va);
	return (ret);
}
