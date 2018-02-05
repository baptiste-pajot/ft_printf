/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse3.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:14:27 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 14:37:13 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_field			*ft_type2(t_field *current, const char *str, int i)
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
	if (str[i] == 'n')
		current->type = N_FLAG;
	return (current);
}

t_field			*ft_type(t_field *current, const char *str, int i)
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
	current = ft_type2(current, str, i);
	current->nb = 5;
	return (current);
}
