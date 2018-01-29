/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 14:27:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:21:51 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_field	*ft_flags(t_field *current, const char *str, int i)
{
	if (str[i] == '#' && !(current->flag & SHARP))
		current->flag += SHARP;
	if (str[i] == '0' && !(current->flag & ZERO))
		current->flag += ZERO;
	if (str[i] == '-' && !(current->flag & MINUS))
		current->flag += MINUS;
	if (str[i] == '+' && !(current->flag & PLUS))
		current->flag += PLUS;
	if (str[i] == ' ' && !(current->flag & SPACE))
		current->flag += SPACE;
	if (str[i] == '*' && !(current->flag & ASTERIX))
		current->flag += ASTERIX;
	if (str[i] == '$' && !(current->flag & DOLLAR))
		current->flag += DOLLAR;
	if (str[i] == 'L' && !(current->flag & L_FLAG))
		current->flag += L_FLAG;
	if (str[i] == '\'' && !(current->flag & APOSTROPHE))
		current->flag += APOSTROPHE;
	if (str[i] == 'b' && !(current->flag & B_FLAG))
		current->flag += B_FLAG;
	if (str[i] == 'r' && !(current->flag & R_FLAG))
		current->flag += R_FLAG;
	if (str[i] == 'k' && !(current->flag & K_FLAG))
		current->flag += K_FLAG;
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
		current->conv = H_FLAG;
	if (str[i] == 'h' && current->nb == 4)
		current->conv = HH_FLAG;
	if (str[i] == 'l' && current->nb < 4)
		current->conv = L_FLAG;
	if (str[i] == 'l' && current->nb == 4)
		current->conv = LL_FLAG;
	if (str[i] == 'j')
		current->conv = J_FLAG;
	if (str[i] == 'z')
		current->conv = Z_FLAG;
	current->nb = 4;
	return (current);
}

static t_field	*ft_type(t_field *current, const char *str, int i)
{
	if (str[i] == '%')
		current->type = PERCENT;
	if (str[i] == 'c')
		current->type = C_MIN;
	if (str[i] == 'C')
		current->type = C_MAJ;
	if (str[i] == 's')
		current->type = S_MIN;
	if (str[i] == 'S')
		current->type = S_MAJ;
	if (str[i] == 'd' || str[i] == 'i')
		current->type = D_MIN;
	if (str[i] == 'D')
		current->type = D_MAJ;
	if (str[i] == 'u')
		current->type = U_MIN;
	if (str[i] == 'U')
		current->type = U_MAJ;
	if (str[i] == 'o')
		current->type = O_MIN;
	if (str[i] == 'O')
		current->type = O_MAJ;
	if (str[i] == 'x')
		current->type = X_MIN;
	if (str[i] == 'X')
		current->type = X_MAJ;
	if (str[i] == 'p')
		current->type = POINTER;
	if (str[i] == 'e')
		current->type = E_MIN;
	if (str[i] == 'E')
		current->type = E_MAJ;
	if (str[i] == 'f')
		current->type = F_MIN;
	if (str[i] == 'F')
		current->type = F_MAJ;
	if (str[i] == 'g')
		current->type = G_MIN;
	if (str[i] == 'G')
		current->type = G_MAJ;
	if (str[i] == 'a')
		current->type = A_MIN;
	if (str[i] == 'A')
		current->type = A_MAJ;
	if (str[i] == 'n')
		current->type = N_FLAG;
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
			printf("flags : %d\nwidth : %d\npreci : %d\nconv : %d\ntype : %d\n",
				current->flag, current->width, current->preci, current->conv,
				current->type);
			current = current->next;
		}
		i++;
	}
	return (begin);
}
