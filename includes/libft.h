/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:46:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/07 21:11:34 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

uintmax_t			ft_abs(intmax_t nb);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_bitlen(intmax_t p);
int					ft_getlinesize(char *buf);
char				*ft_getlline(char *buf, int l);
int					ft_getnbrline(char *buf);
char				*ft_gotoline(char *buf, int l);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islow(int c);
int					ft_isprint(int c);
int					ft_isup(int c);
char				*ft_itoa(int nb);
char				**ft_linesplit(char *s, char c);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_min(int a, int b);
int					ft_nbrlen(intmax_t nb);
int					ft_nbrlenbase(uintmax_t nb, int base);
int					ft_bitlen(long p);
int					ft_pow(int nb, int pow);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl(int n);
void				ft_putnbrendl_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
float				ft_sqrt(float nb);
char				*ft_stradd(char **s1, char const *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strinc(char **ptr, int size, char c);
char				*ft_strdup(const char *s1);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
int					ft_strnloc(char c, void *ptr, int n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				*ft_strstr(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_swapchar(char *a, char *b);
void				ft_swapint(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** PRINTF FUNCTIONS
*/

# define PRINTF_BUFF_SIZE	500

/*
** portabilite
** typedef long long intmax_t;
** typedef unsigned long long uintmax_t;
*/

enum				e_hljz
{
	E_NO = 0,
	E_HH,
	E_H,
	E_L,
	E_LL,
	E_J,
	E_Z
};

enum				e_type
{
	E_INT = 0,
	E_CHAR,
	E_SHORT,
	E_LONG,
	E_LLONG,
	E_INTMAX,
	E_SIZE_T
};

enum				e_flags
{
	E_SHARP = 1 << 4,
	E_ZERO = 1 << 3,
	E_DASH = 1 << 2,
	E_SPACE = 1 << 1,
	E_PLUS = 1
};

typedef struct		s_spec
{
	char			flags;
	int				mfw;
	int				prec;
	char			hljz;
	char			conv;
}					t_spec;

typedef struct		s_print
{
	char			buf[PRINTF_BUFF_SIZE];
	unsigned int	pos;
	va_list			ap;
	void			*convftab[16];
	int				ans;
	t_spec			*spec;
	int				fd;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

void				applyplusspace(t_print *print, t_spec *spec, int s);
void				applysharp(t_print *print, t_spec *spec);
void				applymfw(t_print *print, t_spec *spec, int mfw);
void				applynumprec(t_print *print, t_spec *spec, int len);

void				addto(char c, t_print *print);

int					setflag(t_spec *spec, const char *str);
int					setmfwi(t_print *print, t_spec *spec, const char *str);
int					setprec(t_spec *spec, const char *str);
int					setmodi(t_spec *spec, const char *str);
int					setconv(t_spec *spec, const char *str);

void				conv_b(t_spec *spec, t_print *print);
void				conv_s(t_spec *spec, t_print *print);
void				conv_ls(t_spec *spec, t_print *print);
void				conv_p(t_spec *spec, t_print *print);
void				conv_d(t_spec *spec, t_print *print);
void				conv_ld(t_spec *spec, t_print *print);
void				conv_i(t_spec *spec, t_print *print);
void				conv_o(t_spec *spec, t_print *print);
void				conv_lo(t_spec *spec, t_print *print);
void				conv_u(t_spec *spec, t_print *print);
void				conv_lu(t_spec *spec, t_print *print);
void				conv_x(t_spec *spec, t_print *print);
void				conv_bx(t_spec *spec, t_print *print);
void				conv_c(t_spec *spec, t_print *print);
void				conv_lc(t_spec *spec, t_print *print);
void				conv_mod(t_spec *spec, t_print *print);

int					conv(t_spec *spec, t_print *print, const char *format);

void				sitoa(intmax_t p, t_print *print, int l);
void				uitoabase(uintmax_t p, char *base, t_print *print, int l);

intmax_t			recupparam(int type, va_list ap);
uintmax_t			urecupparam(int type, va_list ap);


/*
** GNL FUNCTIONS
*/

# define GNL_BUFF_SIZE 1

int					get_next_line(int const fd, char **line);

#endif
