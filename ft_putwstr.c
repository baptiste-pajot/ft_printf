/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putwstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 08:26:34 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:02:14 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putwstr(wchar_t *wstr)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (wstr)
	{
		while (wstr[i])
		{
			ret += ft_putwchar(wstr[i]);
			i++;
		}
	}
	return (ret);
}

int				ft_putwstrl(wchar_t *wstr, int l)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (wstr)
	{
		while (wstr[i] && ret + ft_wcharlen(wstr[i]) <= l)
		{
			ret += ft_putwchar(wstr[i]);
			i++;
		}
	}
	return (ret);
}

int				ft_wstrlen(wchar_t *wstr)
{
	size_t		i;
	int			ret;

	i = 0;
	ret = 0;
	if (wstr)
	{
		while (wstr[i])
		{
			ret += ft_wcharlen(wstr[i]);
			i++;
		}
	}
	return (ret);
}

int				ft_wstrlenl(wchar_t *wstr, int l)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (wstr)
	{
		while (wstr[i] && ret + ft_wcharlen(wstr[i]) <= l)
		{
			ret += ft_wcharlen(wstr[i]);
			i++;
		}
	}
	return (ret);
}
