/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwchar.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:23:00 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:33:17 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <unistd.h>

int			ft_putwchar(wchar_t c)
{
	int		i;

	if (c > 0xFFFF && c <= 0x1FFFFF)
	{
		i = 0xF0 + ((c >> 18) & 0x07);
		write(1, &i, 1);
		i = 0x80 + ((c >> 12) & 0x3F);
		write(1, &i, 1);
		i = 0x80 + ((c >> 6) & 0x3F);
		write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		write(1, &i, 1);
		return (4);
	}
	else if (c > 0x7FF)
	{
		i = 0xE0 + ((c >> 12) & 0xF);
		write(1, &i, 1);
		i = 0x80 + ((c >> 6) & 0x3F);
		write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		write(1, &i, 1);
		return (3);
	}
	else if (c > 0x7F)
	{
		i = 0xC0 + ((c >> 6) & 0x1F);
		write(1, &i, 1);
		i = 0x80 + (c & 0x3F);
		write(1, &i, 1);
		return (2);
	}
	else if (c >= 0)
	{
		write(1, &c, 1);
		return (1);
	}
	return (-1);
}
