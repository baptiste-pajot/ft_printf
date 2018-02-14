/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_size.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 19:24:28 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 17:18:54 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_size(char c)
{
//	unsigned char ch;

//	ch = 0;
	return (write(1, &c, 1));
/*	if (c >= 0)
		return(write(1, &c, 1));
	else
	{
		ch = c + 128;
		if (ch >= 64)
		{
			c = 0xc3;
			write(1, &c, 1);
			ch = ch - 64;
		}
		else
		{
			c = 0xc2;
			write(1, &c, 1);
		}
		c = 0x80;
		c = c + ch;
		return(write(1, &c, 1));
	}*/
}

int		ft_putchar_sizel(char c, int i)
{
	int		ret;

	ret = 0;
	while (i > 0)
	{
		ret += write(1, &c, 1);
		i--;
	}
	return (ret);
}
