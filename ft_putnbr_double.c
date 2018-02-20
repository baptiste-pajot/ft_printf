/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_double.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:56:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:40:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_double_int(double d)
{
/*	unsigned long int	*ptr;
	int					s;
	long int			e;
	long int			m;

	ptr = (unsigned long int*)&d;
	s = *ptr >> 63;
	ft_putnbr_long_size(s);
	e = *ptr & 0x7ff0000000000000;
	e >>= 52;
	ft_putendl("");
	ft_putnbr_long_size(e);
	m = *ptr & 0x000fffffffffffff;
	ft_putendl("");
	ft_putnbr_long_size(m);
	ft_putendl("");
	ft_putnbr_long_base(m, 2, 0);*/
	double	buf;
	int		ret;
	double	pow;
	int		len;

	ret = 0;
	buf = d;
	pow = 1.0;
	len = 1;
	while (buf >= 10.0)
	{
		buf /= 10.0;
		len++;
		pow *= 10;
	}
	buf = d;
	while (len > 0)
	{
		ret += ft_putnbr_size((int)(buf / pow));
		buf -= ((int)(buf / pow)) * pow;
		pow /= 10;
		len--;
	}
	return (ret);
}
