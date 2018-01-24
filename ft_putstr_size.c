/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_size.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 09:26:14 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 09:51:50 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_putstr_size(char *str)
{
	if (str)
		return (write(1, str, ft_strlen(str)));
	else
		return (-1);
}
