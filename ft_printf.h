/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:03:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 09:51:44 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

int			ft_printf(const char *format, ...);
int			ft_putwchar(wchar_t c);
int			ft_putstr_size(char *str);
int			ft_putchar_int(int c);
int			ft_putwstr(wchar_t *wstr);

#endif
