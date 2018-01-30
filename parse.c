/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:27:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 12:13:59 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_field			*ft_init(t_field *current)
{
	if ((current = (t_field*)malloc(sizeof(t_field))) == NULL)
		return (NULL);
	current->flag = 0;
	current->width = 0;
	current->preci = 0;
	current->conv = 0;
	current->type = 0;
	current->len = 0;
	current->nb = 0;
	current->next = NULL;
	return (current);
}

static t_field	*ft_parse2(const char *str, int i, t_field *current)
{
	int		len;

	len = 0;
	while (str[++i] && current->nb != 5)
	{
		if (ft_strchr(FLAG, str[i]) != NULL && current->nb < 2)
			current = ft_flags(current, str, i);
		else if (ft_strchr(WIDTH, str[i]) != NULL && current->nb < 2)
			current = ft_width(current, str, i);
		else if (str[i] == '.' && current->nb < 3)
			current = ft_preci(current, str, i);
		else if (ft_strchr(CONV, str[i]) != NULL && current->nb < 5)
			current = ft_sizem(current, str, i);
		else if (ft_strchr(TYPE, str[i]) != NULL)
			current = ft_type(current, str, i);
		len++;
	}
	current->len = len;
	return (current);
}

t_field			*ft_parse(const char *str, t_field *field)
{
	t_field		*current;
	size_t		i;

	i = 0;
	current = field;
	while (str[i])
	{
		if (str[i] == '%')
		{
			current = ft_init(current);
			current = ft_parse2(str, i, current);
			i += current->len;
			printf("flags : %d\nwidth : %d\npreci : %d\nconv : %d\ntype : %d\n",
				current->flag, current->width, current->preci, current->conv,
				current->type);
			current = current->next;
		}
		i++;
	}
	return (field);
}