/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:10:54 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 08:50:25 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_field	*ft_flags2(t_field *current, const char *str, int i)
{
	if (str[i] == '\'' && !(current->flag & APOSTROPHE))
		current->flag += APOSTROPHE;
	if (str[i] == 'b' && !(current->flag & B_FLAG))
		current->flag += B_FLAG;
	if (str[i] == 'r' && !(current->flag & R_FLAG))
		current->flag += R_FLAG;
	if (str[i] == 'k' && !(current->flag & K_FLAG))
		current->flag += K_FLAG;
	return (current);
}

t_field			*ft_flags(t_field *current, const char *str, int i)
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
	current = ft_flags2(current, str, i);
	current->nb = 1;
	return (current);
}

t_field			*ft_width(t_field *current, const char *str, int i)
{
	current->width = ft_atoi(&str[i]);
	current->nb = 2;
	return (current);
}

t_field			*ft_preci(t_field *current, const char *str, int i)
{
	current->preci = ft_atoi(&str[i + 1]);
	current->nb = 3;
	return (current);
}

t_field			*ft_sizem(t_field *current, const char *str, int i)
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
