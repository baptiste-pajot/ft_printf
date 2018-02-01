/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_percent.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 16:12:01 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 18:25:53 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_percent(t_field *current)
{
	int			ret;

	ret = 0;
	if (current)
	{
		ret = ft_putchar_size('%');
	}
	return (ret);
}
