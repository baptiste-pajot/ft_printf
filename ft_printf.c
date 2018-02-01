/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 10:37:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 16:40:33 by bpajot      ###    #+. /#+    ###.fr     */
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
			i = (current) ? current->text : ft_strlen(format) - 1;
		}
	}
	clean(field);
	va_end(va);
	return (ret);
}
