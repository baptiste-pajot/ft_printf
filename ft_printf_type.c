/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_type.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 15:21:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 18:20:53 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_printf_type3(t_field *cur, va_list *va)
{
	if (cur->type & G_MIN)
		ft_printf_g(cur, va);
	if (cur->type & G_MAJ)
		ft_printf_gg(cur, va);
	if (cur->type & A_MIN)
		ft_printf_a(cur, va);
	if (cur->type & A_MAJ)
		ft_printf_aa(cur, va);
	if (cur->type & N_FLAG)
		ft_printf_n(cur, va);
	if (!cur->type && cur->letter)
		ft_printf_z(cur);
	return (cur->ret);
}

static int		ft_printf_type2(t_field *cur, va_list *va)
{
	if (cur->type & O_MIN)
		ft_printf_o(cur, va);
	if (cur->type & O_MAJ)
		ft_printf_oo(cur, va);
	if (cur->type & X_MIN)
		ft_printf_x(cur, va);
	if (cur->type & X_MAJ)
		ft_printf_xx(cur, va);
	if (cur->type & POINTER)
		ft_printf_p(cur, va);
	if (cur->type & E_MIN)
		ft_printf_e(cur, va);
	if (cur->type & E_MAJ)
		ft_printf_ee(cur, va);
	if (cur->type & F_MIN)
		ft_printf_f(cur, va);
	if (cur->type & F_MAJ)
		ft_printf_ff(cur, va);
	ft_printf_type3(cur, va);
	return (cur->ret);
}

int				ft_printf_type(t_field *cur, va_list *va)
{
	if (cur->type & PERCENT)
		ft_printf_percent(cur);
	if ((cur->type & C_MIN) && !(cur->conv & L_FLAG))
		ft_printf_c(cur, va);
	if ((cur->type & C_MAJ) || ((cur->type & C_MIN) && (cur->conv & L_FLAG)))
		ft_printf_cc(cur, va);
	if (cur->type & S_MIN)
		ft_printf_s(cur, va);
	if (cur->type & S_MAJ)
		ft_printf_ss(cur, va);
	if (cur->type & D_MIN)
		ft_printf_d(cur, va);
	if (cur->type & D_MAJ)
		ft_printf_dd(cur, va);
	if (cur->type & U_MIN)
		ft_printf_u(cur, va);
	if (cur->type & U_MAJ)
		ft_printf_uu(cur, va);
	ft_printf_type2(cur, va);
	return (cur->ret);
}
