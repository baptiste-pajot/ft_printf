/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:14:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:55:15 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_check_wchar(wchar_t *p_wchar, t_field *cur)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (p_wchar && p_wchar[i] && (cur->preci == -1 || i < cur->preci))
	{
		if (p_wchar[i] < 0 && ((cur->type == S_MAJ) || (cur->type == S_MIN &&
			cur->conv == L_FLAG)))
			ret = 1;
		if (p_wchar[i] > 255 && MB_CUR_MAX == 1 && ((cur->type == S_MAJ) ||
			(cur->type == S_MIN && cur->conv == L_FLAG)))
			ret = 1;
		if (p_wchar[i] > 0x10ffff && (cur->type == S_MAJ || (cur->type == S_MIN
			&& cur->conv == L_FLAG)))
			ret = 1;
		if (p_wchar[i] > 0xd7ff && p_wchar[i] < 0xe000 && (cur->type == S_MAJ ||
			(cur->type == S_MIN && cur->conv == L_FLAG)))
			ret = 1;
		i++;
	}
	return (ret);
}

static t_field			*ft_type3(t_field *cur, va_list *va)
{
	wchar_t		wchar;
	wchar_t		*p_wchar;

	if ((cur->type == S_MIN && cur->conv == L_FLAG) || cur->type == S_MAJ)
	{
		p_wchar = va_arg(*va, wchar_t*);
		cur->error = ft_check_wchar(p_wchar, cur);
	}
	else
	{
		wchar = va_arg(*va, wchar_t);
		if (wchar < 0 && ((cur->type == C_MAJ) || (cur->type == C_MIN &&
			cur->conv == L_FLAG)))
			cur->error = 1;
		if (wchar > 255 && MB_CUR_MAX == 1 && ((cur->type == C_MAJ) ||
			(cur->type == C_MIN && cur->conv == L_FLAG)))
			cur->error = 1;
		if (wchar > 0x10ffff && (cur->type == C_MAJ || (cur->type == C_MIN
			&& cur->conv == L_FLAG)))
			cur->error = 1;
		if (wchar > 0xd7ff && wchar < 0xe000 && (cur->type == C_MAJ ||
			(cur->type == C_MIN && cur->conv == L_FLAG)))
			cur->error = 1;
	}
	return (cur);
}

static t_field			*ft_type2(t_field *cur, const char *str, int i,
		va_list *va)
{
	if (str[i] == 'x')
		cur->type = X_MIN;
	if (str[i] == 'X')
		cur->type = X_MAJ;
	if (str[i] == 'p')
		cur->type = POINTER;
	if (str[i] == 'e')
		cur->type = E_MIN;
	if (str[i] == 'E')
		cur->type = E_MAJ;
	if (str[i] == 'f')
		cur->type = F_MIN;
	if (str[i] == 'F')
		cur->type = F_MAJ;
	if (str[i] == 'g')
		cur->type = G_MIN;
	if (str[i] == 'G')
		cur->type = G_MAJ;
	if (str[i] == 'a')
		cur->type = A_MIN;
	if (str[i] == 'A')
		cur->type = A_MAJ;
	if (str[i] == 'n')
		cur->type = N_FLAG;
	if (str[i] != '%')
		cur = ft_type3(cur, va);
	return (cur);
}

t_field					*ft_type(t_field *cur, const char *str, int i,
		va_list *va)
{
	if (str[i] == '%')
		cur->type = PERCENT;
	if (str[i] == 'c')
		cur->type = C_MIN;
	if (str[i] == 'C')
		cur->type = C_MAJ;
	if (str[i] == 's')
		cur->type = S_MIN;
	if (str[i] == 'S')
		cur->type = S_MAJ;
	if (str[i] == 'd' || str[i] == 'i')
		cur->type = D_MIN;
	if (str[i] == 'D')
		cur->type = D_MAJ;
	if (str[i] == 'u')
		cur->type = U_MIN;
	if (str[i] == 'U')
		cur->type = U_MAJ;
	if (str[i] == 'o')
		cur->type = O_MIN;
	if (str[i] == 'O')
		cur->type = O_MAJ;
	cur = ft_type2(cur, str, i, va);
	cur->nb = 5;
	return (cur);
}
