/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_double_sci.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:58:48 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 19:59:28 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_get_exponent(char *res)
{
	int		i;
	int		exp;

	i = 0;
	while (res[i] == '0' || res[i] == '.')
	{
		if (res[i] == '.')
		{
			exp = -1;
			while (res[++i] == '0')
				exp--;
			return ((res[i] && res[i] != '0') ? exp : 0);
		}
		i++;
	}
	exp = 0;
	while (res[i] && res[i] != '.')
	{
		i++;
		exp += (res[i] && res[i] != '.') ? 1 : 0;
	}
	return (exp);
}
