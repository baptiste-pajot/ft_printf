/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_type.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 15:21:04 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:51:14 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_type4(t_field *cur, va_list *va)
{
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
}

static void		ft_printf_type3(t_field *cur, va_list *va)
{
	if ((cur->type & O_MAJ) || ((cur->type & O_MIN) && (cur->conv & L_FLAG)))
		ft_printf_lo(cur, va);
	if ((cur->type & O_MIN) && (cur->conv & LL_FLAG))
		ft_printf_llo(cur, va);
	if ((cur->type & O_MIN) && (cur->conv & J_FLAG))
		ft_printf_jo(cur, va);
	if ((cur->type & O_MIN) && (cur->conv & Z_FLAG))
		ft_printf_zo(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & H_FLAG))
		ft_printf_hx(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & HH_FLAG))
		ft_printf_hhx(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && !(cur->conv & (H_FLAG +
		HH_FLAG + L_FLAG + LL_FLAG + J_FLAG + Z_FLAG)))
		ft_printf_x(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & L_FLAG))
		ft_printf_lx(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & LL_FLAG))
		ft_printf_llx(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & J_FLAG))
		ft_printf_jx(cur, va);
	if (((cur->type & X_MIN) || (cur->type & X_MAJ)) && (cur->conv & Z_FLAG))
		ft_printf_zx(cur, va);
	ft_printf_type4(cur, va);
}

static void		ft_printf_type2(t_field *cur, va_list *va)
{
	if ((cur->type & D_MIN) && (cur->conv & Z_FLAG))
		ft_printf_zd(cur, va);
	if ((cur->type & U_MIN) && (cur->conv & H_FLAG))
		ft_printf_hu(cur, va);
	if ((cur->type & U_MIN) && (cur->conv & HH_FLAG))
		ft_printf_hhu(cur, va);
	if ((cur->type & U_MIN) && !(cur->conv & (H_FLAG + HH_FLAG + L_FLAG +
		LL_FLAG + J_FLAG + Z_FLAG)))
		ft_printf_u(cur, va);
	if ((cur->type & U_MAJ) || ((cur->type & U_MIN) && (cur->conv & L_FLAG)))
		ft_printf_lu(cur, va);
	if ((cur->type & U_MIN) && (cur->conv & LL_FLAG))
		ft_printf_llu(cur, va);
	if ((cur->type & U_MIN) && (cur->conv & J_FLAG))
		ft_printf_ju(cur, va);
	if ((cur->type & U_MIN) && (cur->conv & Z_FLAG))
		ft_printf_zu(cur, va);
	if ((cur->type & O_MIN) && (cur->conv & H_FLAG))
		ft_printf_ho(cur, va);
	if ((cur->type & O_MIN) && (cur->conv & HH_FLAG))
		ft_printf_hho(cur, va);
	if ((cur->type & O_MIN) && !(cur->conv & (H_FLAG + HH_FLAG + L_FLAG +
		LL_FLAG + J_FLAG + Z_FLAG)))
		ft_printf_o(cur, va);
	ft_printf_type3(cur, va);
}

int				ft_printf_type(t_field *cur, va_list *va)
{
	if (cur->type & PERCENT)
		ft_printf_percent(cur);
	if ((cur->type & C_MIN) && !(cur->conv & L_FLAG))
		ft_printf_c(cur, va);
	if ((cur->type & C_MAJ) || ((cur->type & C_MIN) && (cur->conv & L_FLAG)))
		ft_printf_cc(cur, va);
	if ((cur->type & S_MIN) && !(cur->conv & L_FLAG))
		ft_printf_s(cur, va);
	if ((cur->type & S_MAJ) || ((cur->type & S_MIN) && (cur->conv & L_FLAG)))
		ft_printf_ss(cur, va);
	if ((cur->type & D_MIN) && (cur->conv & H_FLAG))
		ft_printf_hd(cur, va);
	if ((cur->type & D_MIN) && (cur->conv & HH_FLAG))
		ft_printf_hhd(cur, va);
	if ((cur->type & D_MIN) && !(cur->conv & (H_FLAG + HH_FLAG + L_FLAG +
		LL_FLAG + J_FLAG + Z_FLAG)))
		ft_printf_d(cur, va);
	if ((cur->type & D_MAJ) || ((cur->type & D_MIN) && (cur->conv & L_FLAG)))
		ft_printf_ld(cur, va);
	if ((cur->type & D_MIN) && (cur->conv & LL_FLAG))
		ft_printf_lld(cur, va);
	if ((cur->type & D_MIN) && (cur->conv & J_FLAG))
		ft_printf_jd(cur, va);
	ft_printf_type2(cur, va);
	return (cur->ret);
}
