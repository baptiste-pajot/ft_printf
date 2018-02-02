/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:27:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 10:53:24 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_field		*ft_add(t_field *current, int i)
{
	if (current == NULL)
	{
		if ((current = (t_field*)malloc(sizeof(t_field))) == NULL)
			return (NULL);
	}
	else
	{
		if ((current->next = (t_field*)malloc(sizeof(t_field))) == NULL)
			return (NULL);
		current = current->next;
	}
	current->text = i - 1;
	current->flag = 0;
	current->width = 0;
	current->preci = -1;
	current->conv = 0;
	current->type = 0;
	current->len = 0;
	current->nb = 0;
	current->next = NULL;
	return (current);
}

static t_field		*ft_parse2(const char *str, int i, t_field *current)
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

t_field				*ft_parse(const char *str)
{
	t_field		*current;
	t_field		*begin;
	int			i;

	i = -1;
	begin = NULL;
	current = NULL;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (begin == NULL)
			{
				if ((begin = ft_add(begin, i)) == NULL)
					return (NULL);
				current = begin;
			}
			else if ((current = ft_add(current, i)) == NULL)
				return (NULL);
			current = ft_parse2(str, i, current);
			i += current->len;
		}
	}
	return (begin);
}
//			printf("flags : %d\nwidth : %d\npreci : %d\nconv : %d\ntype : %d\n",
//					current->flag, current->width, current->preci, current->conv,
//					current->type);
