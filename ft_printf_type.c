/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_type.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 15:21:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 15:35:29 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_printf_type3(t_field *current, va_list *va)
{
	int			ret;

	ret = 0;
	if (current->type & G_MIN)
		ret += ft_printf_g(current, va);
	if (current->type & G_MAJ)
		ret += ft_printf_gg(current, va);
	if (current->type & A_MIN)
		ret += ft_printf_a(current, va);
	if (current->type & A_MAJ)
		ret += ft_printf_aa(current, va);
	if (current->type & N_FLAG)
		ret += ft_printf_n(current, va);
	if (!current->type && current->letter)
		ret += ft_putchar_size(current->letter);
	return (ret);
}

static int		ft_printf_type2(t_field *current, va_list *va)
{
	int			ret;

	ret = 0;
	if (current->type & O_MIN)
		ret += ft_printf_o(current, va);
	if (current->type & O_MAJ)
		ret += ft_printf_oo(current, va);
	if (current->type & X_MIN)
		ret += ft_printf_x(current, va);
	if (current->type & X_MAJ)
		ret += ft_printf_xx(current, va);
	if (current->type & POINTER)
		ret += ft_printf_p(current, va);
	if (current->type & E_MIN)
		ret += ft_printf_e(current, va);
	if (current->type & E_MAJ)
		ret += ft_printf_ee(current, va);
	if (current->type & F_MIN)
		ret += ft_printf_f(current, va);
	if (current->type & F_MAJ)
		ret += ft_printf_ff(current, va);
	ret += ft_printf_type3(current, va);
	return (ret);
}

int				ft_printf_type(t_field *current, va_list *va)
{
	int			ret;

	ret = 0;
	if (current->type & PERCENT)
		ret += ft_printf_percent(current);
	if (current->type & C_MIN)
		ret += ft_printf_c(current, va);
	if (current->type & C_MAJ)
		ret += ft_printf_cc(current, va);
	if (current->type & S_MIN)
		ret += ft_printf_s(current, va);
	if (current->type & S_MAJ)
		ret += ft_printf_ss(current, va);
	if (current->type & D_MIN)
		ret += ft_printf_d(current, va);
	if (current->type & D_MAJ)
		ret += ft_printf_dd(current, va);
	if (current->type & U_MIN)
		ret += ft_printf_u(current, va);
	if (current->type & U_MAJ)
		ret += ft_printf_uu(current, va);
	ret += ft_printf_type2(current, va);
	return (ret);
}
