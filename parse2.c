/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:10:54 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:49:41 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static t_field	*ft_flags2(t_field *cur, const char *str, int i)
{
	if (str[i] == '\'' && !(cur->flag & APOSTROPHE))
		cur->flag += APOSTROPHE;
	if (str[i] == 'b' && !(cur->flag & B_FLAG))
		cur->flag += B_FLAG;
	if (str[i] == 'r' && !(cur->flag & R_FLAG))
		cur->flag += R_FLAG;
	if (str[i] == 'k' && !(cur->flag & K_FLAG))
		cur->flag += K_FLAG;
	return (cur);
}

t_field			*ft_flags(t_field *cur, const char *str, int i)
{
	if (str[i] == '#' && !(cur->flag & SHARP))
		cur->flag += SHARP;
	if (str[i] == '0' && !(cur->flag & ZERO))
		cur->flag += ZERO;
	if (str[i] == '-' && !(cur->flag & MINUS))
		cur->flag += MINUS;
	if (str[i] == '+' && !(cur->flag & PLUS))
		cur->flag += PLUS;
	if (str[i] == ' ' && !(cur->flag & SPACE))
		cur->flag += SPACE;
	if (str[i] == '*' && !(cur->flag & ASTERIX))
		cur->flag += ASTERIX;
	if (str[i] == '$' && !(cur->flag & DOLLAR))
		cur->flag += DOLLAR;
	if (str[i] == 'L' && !(cur->flag & L_FLAG))
		cur->flag += L_FLAG;
	cur = ft_flags2(cur, str, i);
	cur->nb = 1;
	return (cur);
}

t_field			*ft_width(t_field *cur, const char *str, int i)
{
	cur->width = ft_atoi(&str[i]);
	cur->nb = 2;
	return (cur);
}

t_field			*ft_preci(t_field *cur, const char *str, int i)
{
	cur->preci = ft_atoi(&str[i + 1]);
	cur->nb = 3;
	return (cur);
}

t_field			*ft_sizem(t_field *cur, const char *str, int i)
{
	if (str[i] == 'h' && str[i + 1] != 'h' && str[i - 1] != 'h')
		cur->conv = H_FLAG;
	if (str[i] == 'h' && str[i + 1] == 'h')
		cur->conv = HH_FLAG;
	if (str[i] == 'l' && str[i + 1] != 'l' && str[i - 1] != 'l')
		cur->conv = L_FLAG;
	if (str[i] == 'l' && str[i + 1] == 'l')
		cur->conv = LL_FLAG;
	if (str[i] == 'j')
		cur->conv = J_FLAG;
	if (str[i] == 'z')
		cur->conv = Z_FLAG;
	cur->nb = 4;
	return (cur);
}
