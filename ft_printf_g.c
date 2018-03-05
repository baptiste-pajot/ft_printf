/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_g.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:31:49 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 18:56:54 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_g(t_field *cur, va_list *va)
{
	double		g;
	t_double	*d;
	char		*buf;
	int			e;

	g = va_arg(*va, double);
	d = ft_double_info(g);
	buf = ft_char_double(d, cur->preci);
	e = ft_get_exponent(buf);
	ft_memdel((void**)&buf);
	if (e < -4 || e >= cur->preci)
		ft_printf_e2(cur, d);
	else
		ft_printf_f2(d, cur);
}

void		ft_printf_lg(t_field *cur, va_list *va)
{
	long double		lg;
	t_double		*d;
	char			*buf;
	int				e;

	lg = va_arg(*va, long double);
	d = ft_longdouble_info(lg);
	buf = ft_char_longdouble(d, cur->preci);
	e = ft_get_exponent(buf);
	ft_memdel((void**)&buf);
	if (e < -4 || e >= cur->preci)
		ft_printf_le2(cur, d);
	else
		ft_printf_lf2(d, cur);
}
