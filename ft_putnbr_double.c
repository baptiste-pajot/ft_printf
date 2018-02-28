/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_double.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:56:11 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 16:59:15 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_double		*ft_double_info(double d)
{
	unsigned long int	*ptr;
	t_double			*d_info;

	if ((d_info = (t_double*)malloc(sizeof(t_double))) == NULL)
		return (NULL);
	ptr = (unsigned long int*)&d;
	d_info->s = *ptr >> 63;
	ft_putnbr(d_info->s);
	ft_putendl("");
	d_info->e = (*ptr & 0x7ff0000000000000) >> 52;
	ft_putnbr(d_info->e);
	ft_putendl("");
	d_info->e -= 1023;
	ft_putnbr(d_info->e);
	ft_putendl("");
	d_info->m = *ptr & 0x000fffffffffffff;
	ft_putnbr_long_base(d_info->m, 2, 0);
	ft_putendl("");
	return (d_info);
}

int				ft_putnbr_double(t_double *d, int preci)
{
	char	*res;
	char	*buff;
	char	*sum;
	int		ret;
	int		pow;
	int		i;

	ret = 0;
	pow = d->e;
	i = 52;
	res = ft_two_pow(d->e);
	while (--i >= 0)
	{
		pow--;
		if ((d->m >> i) % 2)
		{
			buff = ft_two_pow(pow);
			sum = ft_sum(res, buff);
			ft_memdel((void**)&res);
			ft_memdel((void**)&buff);
			res = ft_strdup(sum);
			ft_memdel((void**)&sum);
		}
	}
	buff = ft_round(res, preci);
	ft_memdel((void**)&res);
	ret += ft_putstr_size(buff);
	ft_memdel((void**)&buff);
	return (ret);
}
