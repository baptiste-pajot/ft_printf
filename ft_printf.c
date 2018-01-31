/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 10:37:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 15:04:00 by bpajot      ###    #+. /#+    ###.fr     */
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

static int		ft_printf_type(t_field *current, va_list *va)
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
	//	ret += ft_strlen(ft_itoa(i));
	//	ft_putnbr(i);
		ret += ft_putnbr_size(i);
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

static t_field	*ft_printf_arg(t_field *current, va_list *va, int *i, int *ret)
{
	*ret += ft_printf_type(current, va);
	*i += current->len;
	current = current->next;
	return (current);
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
	while (format[++i])
	{
		if (format[i] == '%')
			current = ft_printf_arg(current, &va, &i, &ret);
		else
		{
			ret += (current) ? ft_putstr_sizel((char*)&(format[i]),
				current->text - i + 1) : ft_putstr_size((char*)&format[i]);
		//	ret += (current) ? ft_putstr_size((char*)ft_strsub(format, i,
		//		current->text - i + 1)) : ft_putstr_size((char*)&format[i]);
			i = (current) ? current->text : ft_strlen(format) - 1;
		}
	}
	clean(field);
	va_end(va);
	return (ret);
}
