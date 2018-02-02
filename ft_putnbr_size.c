/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_size.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 14:53:54 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 08:49:47 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_size(int n)
{
	int		ret;

	ret = 0;
	if (n != -2147483648)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
			ret++;
		}
		if (n >= 10)
		{
			ret += ft_putnbr_size(n / 10);
			ret += ft_putnbr_size(n % 10);
		}
		else
			ret += ft_putchar_size(n + 48);
	}
	else
		ret = ft_putstr_size("-2147483648");
	return (ret);
}

int		ft_putnbr_long_size(long int n)
{
	int		ret;

	ret = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ret++;
	}
	if (n >= 10)
	{
		ret += ft_putnbr_long_size(n / 10);
		ret += ft_putnbr_long_size(n % 10);
	}
	else
		ret += ft_putchar_size(n + 48);
	return (ret);
}

int		ft_putnbr_u_size(unsigned int n)
{
	int		ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr_u_size(n / 10);
		ret += ft_putnbr_u_size(n % 10);
	}
	else
		ret += ft_putchar_size(n + 48);
	return (ret);
}

int		ft_putnbr_u_long_size(unsigned long int n)
{
	int		ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_putnbr_u_long_size(n / 10);
		ret += ft_putnbr_u_long_size(n % 10);
	}
	else
		ret += ft_putchar_size(n + 48);
	return (ret);
}
