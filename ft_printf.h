/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:03:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:03:53 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>

# define FLAG		"#0-+ *$L'brk"
# define WIDTH		"123456789"
# define CONV		"hljz"
# define TYPE		"sSpdDioOuUxXcCeEfFgGaAn%"

# define SHARP		0x1
# define ZERO		0x2
# define MINUS		0x4
# define PLUS		0x8
# define SPACE		0x10
# define ASTERIX	0x20
# define DOLLAR		0x40
# define L_MAJ		0x80
# define APOSTROPHE	0x100
# define B_FLAG		0x200
# define R_FLAG		0x400
# define K_FLAG		0x800

# define HH_FLAG	0x1
# define H_FLAG		0x2
# define L_FLAG		0x4
# define LL_FLAG	0x8
# define J_FLAG		0x10
# define Z_FLAG		0x20

# define PERCENT	0x1
# define C_MIN		0x2
# define C_MAJ		0x4
# define S_MIN		0x8
# define S_MAJ		0x10
# define D_MIN		0x20
# define D_MAJ		0x40
# define U_MIN		0x80
# define U_MAJ		0x100
# define O_MIN		0x200
# define O_MAJ		0x400
# define X_MIN		0x800
# define X_MAJ		0x1000
# define POINTER	0x2000
# define E_MIN		0x4000
# define E_MAJ		0x8000
# define F_MIN		0x10000
# define F_MAJ		0x20000
# define G_MIN		0x40000
# define G_MAJ		0x80000
# define A_MIN		0x100000
# define A_MAJ		0x200000
# define N_FLAG		0x400000

typedef struct		s_field
{
	int				text;
	int				flag;
	int				width;
	int				preci;
	int				conv;
	int				type;
	int				len;
	int				nb;
	struct s_field	*next;
}					t_field;

t_field				*ft_parse(const char *str);
t_field				*ft_flags(t_field *current, const char *str, int i);
t_field				*ft_width(t_field *current, const char *str, int i);
t_field				*ft_preci(t_field *current, const char *str, int i);
t_field				*ft_sizem(t_field *current, const char *str, int i);
t_field				*ft_type(t_field *current, const char *str, int i);
int					ft_printf(const char *format, ...);
int					ft_putwchar(wchar_t c);
int					ft_putstr_size(char *str);
int					ft_putchar_int(int c);
int					ft_putwstr(wchar_t *wstr);

#endif
