/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpajot <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 11:03:59 by bpajot       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 16:04:54 by bpajot      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
	int				ret;
	int				l;
	int				spc_bfr;
	int				spc_aft;
	int				zero;
	int				plus;
	int				minus;
	int				pos;
	long int		pos_long;
	char			letter;
	struct s_field	*next;
}					t_field;

t_field				*ft_parse(const char *str);
t_field				*ft_flags(t_field *current, const char *str, int i);
t_field				*ft_width(t_field *current, const char *str, int i);
t_field				*ft_preci(t_field *current, const char *str, int i);
t_field				*ft_sizem(t_field *current, const char *str, int i);
t_field				*ft_type(t_field *current, const char *str, int i);
int					ft_printf(const char *format, ...);
int					ft_printf_type(t_field *current, va_list *va);
void				ft_printf_percent(t_field *current);
void				ft_printf_c(t_field *current, va_list *va);
void				ft_printf_cc(t_field *current, va_list *va);
void				ft_printf_z(t_field *cur);
void				ft_printf_s(t_field *current, va_list *va);
void				ft_printf_ss(t_field *current, va_list *va);
void				ft_printf_hd(t_field *current, va_list *va);
void				ft_printf_hhd(t_field *current, va_list *va);
void				ft_printf_d(t_field *current, va_list *va);
void				ft_printf_ld(t_field *current, va_list *va);
void				ft_printf_lld(t_field *current, va_list *va);
void				ft_printf_jd(t_field *cur, va_list *va);
void				ft_printf_zd(t_field *cur, va_list *va);
void				ft_printf_d_flag(t_field *cur);
void				ft_printf_d_space(t_field *cur);
void				ft_printf_u(t_field *current, va_list *va);
void				ft_printf_uu(t_field *current, va_list *va);
void				ft_printf_o(t_field *current, va_list *va);
void				ft_printf_oo(t_field *current, va_list *va);
void				ft_printf_x(t_field *current, va_list *va);
void				ft_printf_xx(t_field *current, va_list *va);
void				ft_printf_p(t_field *current, va_list *va);
void				ft_printf_e(t_field *current, va_list *va);
void				ft_printf_ee(t_field *current, va_list *va);
void				ft_printf_f(t_field *current, va_list *va);
void				ft_printf_ff(t_field *current, va_list *va);
void				ft_printf_g(t_field *current, va_list *va);
void				ft_printf_gg(t_field *current, va_list *va);
void				ft_printf_a(t_field *current, va_list *va);
void				ft_printf_aa(t_field *current, va_list *va);
void				ft_printf_n(t_field *current, va_list *va);
int					ft_putwchar(wchar_t c);
int					ft_wcharlen(wchar_t c);
int					ft_putstr_size(char *str);
int					ft_putstr_sizel(char *str, int i);
int					ft_putchar_size(char c);
int					ft_putchar_sizel(char c, int i);
int					ft_putwstr(wchar_t *wstr);
int					ft_putwstrl(wchar_t *wstr, int l);
int					ft_wstrlen(wchar_t *wc);
int					ft_wstrlenl(wchar_t *wc, int l);
int					ft_putnbr_size(int n);
int					ft_putnbr_long_size(long int n);
int					ft_putnbr_u_size(unsigned int n);
int					ft_putnbr_u_long_size(unsigned long int n);
int					ft_putnbr_base(unsigned int n, unsigned int base, int maj);
int					ft_putnbr_long_base(unsigned long n, unsigned long base,
		int maj);
int					ft_nbr_size(int n);
int					ft_nbr_long_size(long int n);
int					ft_nbr_u_size(unsigned int n);
int					ft_nbr_u_long_size(unsigned long int n);
int					ft_nbr_size_base(unsigned int n, unsigned int base);
int					ft_nbr_long_size_base(unsigned long int n,
		unsigned long int base);

#endif
