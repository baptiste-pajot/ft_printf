/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_round.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 17:29:36 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 16:58:22 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_frac_zero(int preci, int one)
{
	char	*frac_zero;
	int		i;

	if ((frac_zero = ft_strnew(2 + preci)) == NULL)
		return (NULL);
	i = 1;
	frac_zero[0] = '0';
	frac_zero[1] = '.';
	while (++i < preci + 2 - one)
		frac_zero[i] = '0';
	frac_zero[i] = (one) ? '1' : frac_zero[i];
	return (frac_zero);
}

static char		*ft_round_preci_null(char *res_int, char *res_frac)
{
	char	*frac_zero;

	frac_zero = ((res_frac && res_frac[2] >= '5') ? ft_sum(res_int,
				"1") : ft_strdup(res_int));
	ft_memdel((void**)&res_int);
	ft_memdel((void**)&res_frac);
	return (frac_zero);
}

char			*ft_round(char *s, int preci)
{
	char	*res_int;
	char	*res_frac;
	char	*res_frac_new;
	char	*frac_zero;
	int		len_frac;

	res_int = ft_integer(s);
	res_frac = ft_fraction(s);
	len_frac = (res_frac) ? ft_strlen(res_frac) - 2 : 0;
	if (!preci)
		return (ft_round_preci_null(res_int, res_frac));
	else if (preci >= len_frac)
		frac_zero = ft_frac_zero(preci, 0);
	else
		frac_zero = (res_frac[2 + preci] >= '5') ? ft_frac_zero(preci, 1) :
			ft_frac_zero(preci, 0);
	if (preci < len_frac)
		res_frac[ft_strlen(frac_zero)] = '\0';
	res_frac_new = ft_sum(res_frac, frac_zero);
	ft_memdel((void**)&res_frac);
	ft_memdel((void**)&frac_zero);
	res_frac = ft_sum(res_int, res_frac_new);
	ft_memdel((void**)&res_int);
	ft_memdel((void**)&res_frac_new);
	return (res_frac);
}
