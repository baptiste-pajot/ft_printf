/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:13:24 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 11:15:26 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_d(t_field *current, va_list *va)
{
	int			d;
	int			pos;
	int			ret;
	int			len;
	int			neg;

	ret = 0;
	neg = 0;
	d = va_arg(*va, int);
	len = current->width - ft_nbr_size(d);
	if ((current->flag & PLUS) && d >= 0)
		len--;
	if (current->preci > ft_nbr_size(d))
		len -= current->preci - ft_nbr_size(d);
	if ((current->flag & SPACE) && !(current->flag & PLUS) && d >= 0)
	{
		ret+= ft_putchar_size(' ');
		len--;
	}
	if (!(current->flag & ZERO) && !(current->flag & MINUS))
		ret += ft_putchar_sizel(' ', len);
	if (d < 0)
	{
		ret += ft_putchar_size('-');
		neg = 1;
	}
	if (d < 0 && d != -2147483648)
		pos = -d;
	else
		pos = d;
	if ((current->flag & PLUS) && d >= 0)
		ret+= ft_putchar_size('+');
	if ((current->flag & ZERO) && !(current->flag & MINUS) && current->preci != 0)
		ret += ft_putchar_sizel('0', len);
	if ((current->flag & ZERO) && !(current->flag & MINUS) && current->preci > 0)
		ret += ft_putchar_sizel(' ', current->width - current->preci - neg);
	ret += ft_putchar_sizel('0', current->preci - ft_nbr_size(d) + neg);
	if (d != -2147483648 && current->preci)
		ret += ft_putnbr_size(pos);
	else if (current->preci)
		ret += ft_putstr_size("2147483648");
	if (current->flag & MINUS)
		ret += ft_putchar_sizel(' ', len);
	return (ret);
}

int			ft_printf_dd(t_field *current, va_list *va)
{
	long int	dd;
	int			ret;

	dd = 0L;
	ret = 0;
	if (current)
	{
		dd = va_arg(*va, long int);
		ret += ft_putnbr_long_size(dd);
	}
	return (ret);
}
