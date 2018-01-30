/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 10:37:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 12:11:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		clean(t_field *field)
{
	t_field		*next;

	next = NULL;
	if (field)
	{
		next = field->next;
		ft_init(field);
		ft_memdel((void**)&field);
	}
	while (next)
	{
		field = next;
		next = field->next;
		ft_init(field);
		ft_memdel((void**)&field);
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_field		*field;

	field = NULL;
	field = ft_parse(format, field);
	return (clean(field));
}
