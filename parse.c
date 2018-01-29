/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:27:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:52:15 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_field	*ft_flags(t_field *current, const char *str, int i)
{
	if (str[i] == '#')
		current->flag += 0x1 ;
	if (str[i] == '0')
		current->flag += 0x2 ;
	if (str[i] == '-')
		current->flag += 0x4;
	if (str[i] == '+')
		current->flag += 0x8;
	if (str[i] == ' ')
		current->flag += 0x10;
	if (str[i] == '*')
		current->flag += 0x20;
	if (str[i] == '$')
		current->flag += 0x40;
	if (str[i] == 'L')
		current->flag += 0x80;
	if (str[i] == '\'')
		current->flag += 0x100;
	if (str[i] == 'b')
		current->flag += 0x200;
	if (str[i] == 'r')
		current->flag += 0x400;
	if (str[i] == 'k')
		current->flag += 0x800;
	current->nb = 1;
	return (current);
}

static t_field	*ft_width(t_field *current, const char *str, int i)
{
	current->width = ft_atoi(&str[i]);
	current->nb = 2;
	return (current);
}

static t_field	*ft_preci(t_field *current, const char *str, int i)
{
	current->preci = ft_atoi(&str[i + 1]);
	current->nb = 3;
	return (current);
}

static t_field	*ft_sizem(t_field *current, const char *str, int i)
{
	if (str[i] == 'h' && current->nb < 4)
		current->conv = 0x2;
	if (str[i] == 'h' && current->nb == 4)
		current->conv = 0x1;
	if (str[i] == 'l' && current->nb < 4)
		current->conv = 0x4;
	if (str[i] == 'l' && current->nb == 4)
		current->conv = 0x8;
	if (str[i] == 'j')
		current->conv = 0x10 ;
	if (str[i] == 'z')
		current->conv = 0x20 ;
	current->nb = 4;
	return (current);
}

static t_field	*ft_type(t_field *current, const char *str, int i)
{
	if (str[i] == '%')
		current->type = 0x1;
	if (str[i] == 'c')
		current->type = 0x2;
	if (str[i] == 'C')
		current->type = 0x4;
	if (str[i] == 's')
		current->type = 0x8;
	if (str[i] == 'S')
		current->type = 0x10;
	if (str[i] == 'd' || str[i] == 'i')
		current->type = 0x20;
	if (str[i] == 'D')
		current->type = 0x40;
	if (str[i] == 'u')
		current->type = 0x80;
	if (str[i] == 'U')
		current->type = 0x100;
	if (str[i] == 'o')
		current->type = 0x200;
	if (str[i] == 'O')
		current->type = 0x400;
	if (str[i] == 'x')
		current->type = 0x800;
	if (str[i] == 'X')
		current->type = 0x1000;
	if (str[i] == 'p')
		current->type = 0x2000;
	if (str[i] == 'e')
		current->type = 0x4000;
	if (str[i] == 'E')
		current->type = 0x8000;
	if (str[i] == 'f')
		current->type = 0x10000;
	if (str[i] == 'F')
		current->type = 0x20000;
	if (str[i] == 'g')
		current->type = 0x40000;
	if (str[i] == 'G')
		current->type = 0x80000;
	if (str[i] == 'a')
		current->type = 0x100000;
	if (str[i] == 'A')
		current->type = 0x200000;
	if (str[i] == 'n')
		current->type = 0x400000;
	current->nb = 5;
	return (current);
}

static t_field	*ft_parse2(const char *str, int i, t_field *current)
{
	int		len;

	len = 0;
	while (str[++i] && current->nb != 5)
	{
		if (ft_strchr("#0-+ *$L'brk", str[i]) != NULL && current->nb < 2)
			current = ft_flags(current, str, i);
		else if (ft_strchr("123456789", str[i]) != NULL && current->nb < 2)
			current = ft_width(current, str, i);
		else if (str[i] == '.' && current->nb < 3)
			current = ft_preci(current, str, i);
		else if (ft_strchr("hljz", str[i]) != NULL && current->nb < 5)
			current = ft_sizem(current, str, i);
		else if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAn%", str[i]) != NULL)
			current = ft_type(current, str, i);
		len++;
	}
	current->len = len; 
	return (current);
}

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
	return (current);
}

t_field			*ft_parse(const char *str)
{
	t_field		*begin;
	t_field		*current;
	size_t		i;

	begin = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			current = ft_init(current);
			if (begin == NULL)
				begin = current;
			current = ft_parse2(str, i, current);
			i += current->len;
			//printf("%d\n%d\n%d\n%d\n%d\n", current->flag, current->width,
			//	current->preci, current->conv, current->type);
			current = current->next;
		}
		i++;
	}
	return (begin);
}
