/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:14:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 14:13:07 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_field			*ft_type3(t_field *current, const char *str, int i, va_list *va)
{
	int		val;

	if (str[i] == 'n')
		current->type = N_FLAG;
	val = va_arg(*va, int);
//	printf("val = %d\n", val);
	if (val < 0 && (current->type == C_MAJ))// || (current->type == C_MIN &&
//		current->conv == L_FLAG)))
		current->error = 1;
	if (val > 255 && current->type == C_MAJ && MB_CUR_MAX == 1)
		current->error = 1;
	if (val > 0x10ffff && (current->type == C_MAJ || (current->type == C_MIN &&
		current->conv == L_FLAG)))
		current->error = 1;
//	if (val > 0xd7ff && val < 0xe000 && (current->type == C_MAJ ||
//		(current->type == C_MIN && current->conv == L_FLAG)))
//		current->error = 1;
	return (current);
}

t_field			*ft_type2(t_field *current, const char *str, int i, va_list *va)
{
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
	current = ft_type3(current, str, i, va);
	return (current);
}

t_field			*ft_type(t_field *current, const char *str, int i, va_list *va)
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
	current = ft_type2(current, str, i, va);
	current->nb = 5;
	return (current);
}
