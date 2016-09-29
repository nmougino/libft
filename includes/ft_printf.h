/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:46:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 17:44:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** PRINTF FUNCTIONS
*/

# define PRINTF_BUFF_SIZE	500

/*
** portabilite
** typedef long long intmax_t;
** typedef unsigned long long uintmax_t;
*/

enum				e_printf_hljz
{
	E_NO = 0,
	E_HH,
	E_H,
	E_L,
	E_LL,
	E_J,
	E_Z
};

enum				e_printf_type
{
	E_INT = 0,
	E_CHAR,
	E_SHORT,
	E_LONG,
	E_LLONG,
	E_INTMAX,
	E_SIZE_T
};

enum				e_printf_flags
{
	E_SHARP = 1 << 4,
	E_ZERO = 1 << 3,
	E_DASH = 1 << 2,
	E_SPACE = 1 << 1,
	E_PLUS = 1
};

typedef struct		s_printf_spec
{
	int				mfw;
	int				prec;
	char			hljz;
	char			flags;
	char			conv;
	size_t			padding:40;
}					t_printf_spec;

typedef struct		s_print
{
	va_list			ap;
	t_printf_spec	*spec;
	void			(*convftab[16])(t_printf_spec *, struct s_print *);
	int				ans;
	int				fd;
	unsigned int	pos;
	char			buf[PRINTF_BUFF_SIZE];
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

void				applyplusspace(t_print *print, t_printf_spec *spec, int s);
void				applysharp(t_print *print, t_printf_spec *spec);
void				applymfw(t_print *print, t_printf_spec *spec, intmax_t mfw);
void				applynumprec(t_print *print, t_printf_spec *spec,
					size_t len);

void				addto(char c, t_print *print);

int					setflag(t_printf_spec *spec, const char *str);
int					setmfwi(t_print *print, t_printf_spec *spec,
					const char *str);
int					setprec(t_printf_spec *spec, const char *str);
int					setmodi(t_printf_spec *spec, const char *str);
int					setconv(t_printf_spec *spec, const char *str);

void				conv_b(t_printf_spec *spec, t_print *print);
void				conv_s(t_printf_spec *spec, t_print *print);
void				conv_ls(t_printf_spec *spec, t_print *print);
void				conv_p(t_printf_spec *spec, t_print *print);
void				conv_d(t_printf_spec *spec, t_print *print);
void				conv_ld(t_printf_spec *spec, t_print *print);
void				conv_i(t_printf_spec *spec, t_print *print);
void				conv_o(t_printf_spec *spec, t_print *print);
void				conv_lo(t_printf_spec *spec, t_print *print);
void				conv_u(t_printf_spec *spec, t_print *print);
void				conv_lu(t_printf_spec *spec, t_print *print);
void				conv_x(t_printf_spec *spec, t_print *print);
void				conv_bx(t_printf_spec *spec, t_print *print);
void				conv_c(t_printf_spec *spec, t_print *print);
void				conv_lc(t_printf_spec *spec, t_print *print);
void				conv_mod(t_printf_spec *spec, t_print *print);

int					conv(t_printf_spec *spec, t_print *print,
					const char *format);

void				sitoa(intmax_t p, t_print *print, size_t l);
void				uitoabase(uintmax_t p, char *base, t_print *print,
					size_t l);

intmax_t			recupparam(int type, va_list ap);
uintmax_t			urecupparam(int type, va_list ap);

#endif
