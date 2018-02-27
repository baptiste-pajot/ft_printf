/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_float_operation.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 11:17:39 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 11:55:06 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char*		two_times(char *factor)
{
	int		len_factor;
	int		len_product;
	char	*product;
	int		i;
	int		carry;

	len_factor = ft_strlen(factor);
	len_product = (factor[0] >= '5') ? len_factor + 1 : len_factor;
	if ((product = ft_strnew(len_product)) == NULL)
		return (NULL);
	i = len_product;
	carry = 0;
	while (--i >= 0)
	{
		if (factor[0] < '5')
		{
			if (factor[i] < '5')
			{
				product[i] = ((factor[i] - '0') * 2) + '0' + carry;
				carry = 0;
			}
			else
			{
				product[i] = ((factor[i] - '0') * 2) % 10 + '0';
				carry = 1;
			}
		}
		else
		{
			if (!i)
				product[0] = carry + '0';
			else if (factor[i - 1] < '5')
			{
				product[i] = ((factor[i - 1] - '0') * 2) + '0' + carry;
				carry = 0;
			}
			else
			{
				product[i] = ((factor[i - 1] - '0') * 2) % 10 + '0';
				carry = 1;
			}
		}
	}
	return (product);
}
