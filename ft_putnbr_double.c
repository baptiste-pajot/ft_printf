/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_double.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:56:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/21 18:59:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_double_info(double d)
{
	unsigned long int	*ptr;
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
	ft_putnbr_long_base(m, 2, 0);
}

int		ft_putnbr_double_int(double d)
{
	double		buf;
	int			ret;
//	double		pow;
	int			len;
	int			i;
	double		tab_pow[20] = {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0,
	1000000.0, 10000000.0, 100000000.0, 1000000000.0, 10000000000.0,
	100000000000.0, 1000000000000.0, 10000000000000.0, 100000000000000.0,
	1000000000000000.0, 10000000000000000.0, 100000000000000000.0,
	1000000000000000000.0, 10000000000000000000.0};

	ret = 0;
	buf = d;
	i = 0;
//	pow = 1.0;
	len = 1;
	while (buf >= 10.0)
	{
	//	buf /= 10.0;
		buf = d / tab_pow[i + 1];
		len++;
		i++;
	//	pow *= 10.0;
	}
	buf = d;
	while (len > 0)
	{
	//	ret += ft_putnbr_size((int)(buf / pow));
		ret += ft_putnbr_size((int)(buf /tab_pow[i]));
	//	buf -= ((int)(buf / pow)) * pow;
		buf -= ((int)(buf / tab_pow[i])) * tab_pow[i];
		i--;
	//	pow /= 10.0;
		len--;
	}
	return (ret);
}
