/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:23:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:19:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putwchar2(wchar_t c)
{
	int		i;
	int		ret;

	ret = 0;
	if (c > 0x7F) // && c <= 0x7FF)
	{
		i = 0xC0 + ((c >> 6) & 0x1F);
		ret += write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		ret += write(1, &i, 1);
	//	return (2);
		return (ret);
	}
	else if (c >= 0 ) //&& c <= 0x7F)
	{
		ret += write(1, &c, 1);
	//	return (1);
		return (ret);
	}
	return (-1);
}

int				ft_putwchar(wchar_t c)
{
	int		i;
	int		ret;

	ret = 0;
	if (c > 0xFFFF) //  && c <= 0x10FFFF)
	{
		i = 0xF0 + ((c >> 18) & 0x07);
		ret += write(1, &i, 1);
		i = 0x80 + ((c >> 12) & 0x3F);
		ret += write(1, &i, 1);
		i = 0x80 + ((c >> 6) & 0x3F);
		ret += write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		ret += write(1, &i, 1);
	//	return (4);
		return (ret);
	}
	else if (c > 0x7FF && (c < 0xD800 || c > 0xDFFF))
	{
		i = 0xE0 + ((c >> 12) & 0xF);
		ret += write(1, &i, 1);
		i = 0x80 + ((c >> 6) & 0x3F);
		ret += write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		ret += write(1, &i, 1);
	//	return (3);
		return (ret);
	}
	return (ft_putwchar2(c));
}

int				ft_wcharlen(wchar_t c)
{
	if (c > 0xFFFF)// && c <= 0x1FFFFF)
		return (4);
	else if (c > 0x7FF && (c < 0xD800 || c > 0xDFFF))
		return (3);
	else if (c > 0x7F)
		return (2);
	else if (c >= 0)
		return (1);
	return (-1);
}
