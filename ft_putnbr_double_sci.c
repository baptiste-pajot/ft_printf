/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_double_sci.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 18:58:48 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 15:52:10 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_get_exponent(char *res)
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

static char		*ft_char_exp_double(int e, t_field *cur)
{
	char	*exp;
	int		l;

	l = (e * e >= 100 * 100) ? 5 : 4;
	exp = ft_strnew(l);
	exp[0] = (cur->type & E_MAJ) ? 'E' : 'e';
	exp[1] = (e < 0) ? '-' : '+';
	if (e >= 0)
	{
		exp[2] = (e >= 100) ? e / 100 + '0' : e / 10 + '0';
		exp[3] = (e >= 100) ? e % 100 / 10 + '0' : e % 10 + '0';
		exp[4] = (e >= 100) ? e % 10 + '0' : 0;
	}
	else
	{
		exp[2] = (e <= -100) ? -e / 100 + '0' : -e / 10 + '0';
		exp[3] = (e <= -100) ? -e % 100 / 10 + '0' : -e % 10 + '0';
		exp[4] = (e <= -100) ? -e % 10 + '0' : 0;
	}
	return (exp);
}

char		*ft_char_dec_to_sci(char *dec, int preci, int e)
{
	char	*sci;
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	sci = (preci == 0) ? ft_strnew(1) : ft_strnew(2 + preci);
	if (e >= 0)
	{
		sci[0] = dec[0];
		if (preci > 0)
		{
			sci[1] = '.';
			while (i < preci)
			{
				dot += (dec[1 + i] == '.' && !dot) ? 1 : 0;
				sci[2 + i] = dec[1 + i + dot];
				i++;
			}
		}
	}
	else
	{
		while (dec[i] == '0' || dec[i] == '.')
			i++;
		sci[0] = dec[i];
		sci[1] = (preci) ? '.' : 0;
		while (dot < preci)
		{
			sci[2 + dot] = dec[1 + i + dot];
			dot++;
		}
	}
	ft_memdel((void**)&dec);
	return (sci);
}

static char		*ft_char_double_sci(t_double *d, t_field *cur)
{
	char	*res;
	char	*buf;
	int		e;
	char	*exp;

	buf = ft_two_pow(d->e - 53);
	e = ft_get_exponent(buf);
	ft_memdel((void**)&buf);
	buf = (e < 0) ? ft_char_double(d, cur->preci - e + 1) :
		ft_char_double(d, cur->preci + 1);
	e = ft_get_exponent(buf);
	res = ft_char_dec_to_sci(buf, cur->preci + 1, e);
	buf = ft_round(res, cur->preci);
	if (buf[0] == '0' || buf[2] == '.')
	{
		e += (buf[0] == '0') ? -1 : 1;
		buf[1] = (buf[0] == 0) ? buf[2] : '.';
		buf[2] = (buf[0] == 0) ? '.' : '0';
		buf[cur->preci + 2] = 0;
	}
	exp = ft_char_exp_double(e, cur);
	ft_memdel((void**)&res);
	res = ft_strjoin(buf, exp);
	ft_memdel((void**)&buf);
	ft_memdel((void**)&exp);
	return (res);
}

int				ft_putnbr_double_sci(t_double *d, t_field *cur)
{
	int		ret;
	char	*buf;
	char	*exp;

	ret = 0;
	if (d->e == 1024 && d->m == 0)
		ret += (cur->type & E_MAJ) ? ft_putstr_size("INF") :
			ft_putstr_size("inf");
	else if (d->e == 1024)
		ret += (cur->type & E_MAJ) ? ft_putstr_size("NAN") :
			ft_putstr_size("nan");
	else if (d->e == -1023 && d->m == 0)
	{
		ret += ft_putnbr_size(0);
		ret += (cur->preci) ? ft_putchar_size('.') : 0;
		ret += (cur->preci) ? ft_putchar_sizel('0', cur->preci) : 0;
		exp = ft_char_exp_double(0, cur);
		ret += ft_putstr_size(exp);
		ft_memdel((void**)&exp);
	}
	else
	{
		buf = ft_char_double_sci(d, cur);
		ret += ft_putstr_size(buf);
		ft_memdel((void**)&buf);
	}
	return (ret);
}

int				ft_doublelen_sci(t_double *d, t_field *cur)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (d->e == 1024)
		ret = 3;
	else if (d->e == -1023 && d->m == 0)
		ret = (cur->preci) ? cur->preci + 6 : 5;
	else
	{
		buf = ft_char_double_sci(d, cur);
		ret += ft_strlen(buf);
		ft_memdel((void**)&buf);
	}
	return (ret);
}
