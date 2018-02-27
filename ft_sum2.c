/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sum2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 17:21:53 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 17:29:30 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_inf_one(char *s)
{
	int		i;

	i = 0;
	while (i <= (int)ft_strlen(s) && s[i] != '.')
	{
		if (s[i] != '0')
			return (-1);
		i++;
	}
	if (i > (int)ft_strlen(s))
		return (-1);
	else
		return (i);
}

int				ft_dot(char *s)
{
	int		i;

	i = 0;
	while (i <= (int)ft_strlen(s) && s[i] != '.')
	{
		i++;
	}
	if (i > (int)ft_strlen(s))
		return (-1);
	else
		return (i);
}

char			*ft_integer(char *s1)
{
	int		i;
	char	*result;
	int		len;

	i = ft_dot(s1);
	if (i >= 0)
		len = i;
	else
		len = ft_strlen(s1);
	result = ft_strsub(s1, 0, len);
	result[len] = 0;
	return (result);
}

char			*ft_fraction(char *s1)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	i = ft_dot(s1);
	len = 2;
	if (i < 0)
		return (NULL);
	if ((result = ft_strnew(len + ft_strlen(s1) - i)) == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '.';
	j = 2;
	while (++i < (int)ft_strlen(s1))
		result[j++] = s1[i];
	return (result);
}
