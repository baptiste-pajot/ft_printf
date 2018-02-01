/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_p.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:33:06 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 18:04:06 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_p(t_field *current, va_list *va)
{
	unsigned long int	p;
	int					ret;

	ret = 0;
	p =  0L;
	if (current)
	{
		p = va_arg(*va, unsigned long int);
		ret += ft_putstr_size("0x");
		ret += ft_putnbr_long_base(p, 16, 0);
	}
	return (ret);
}
