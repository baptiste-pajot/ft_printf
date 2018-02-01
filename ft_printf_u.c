/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_u.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:33:40 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 17:15:09 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_u(t_field *current, va_list *va)
{
	unsigned int	u;
	int				ret;

	u = 0;
	ret = 0;
	if (current)
	{
		u = va_arg(*va, unsigned int);
		ret += ft_putnbr_u_size(u);
	}
	return (ret);
}

int		ft_printf_uu(t_field *current, va_list *va)
{
	unsigned long int	uu;
	int					ret;

	uu = 0L;
	ret = 0;
	if (current)
	{
		uu = va_arg(*va, unsigned long int);
		ret += ft_putnbr_u_size(uu);
	}
	return (ret);
}
