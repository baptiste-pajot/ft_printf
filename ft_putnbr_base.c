/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 17:06:48 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 17:38:16 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_base(unsigned int n, unsigned int base)
{
	int		ret;

	ret = 0;
	if (n >= base)
	{
		ret += ft_putnbr_base(n / base, base);
		ret += ft_putnbr_base(n % base, base);
	}
	else if (n < 10)
		ret += ft_putchar_int(n + '0');
	else
		ret += ft_putchar_int(n + 'A' - 10);
	return (ret);
}
