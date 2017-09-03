/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:46:12 by nmougino          #+#    #+#             */
/*   Updated: 2017/09/03 20:38:36 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf.h"

/*
** portabilite
*/

typedef long int			t_intmax;
typedef unsigned long int	t_uintmax;

typedef	struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef	struct				s_dlist
{
	void					*content;
	size_t					content_size;
	struct s_dlist			*next;
	struct s_dlist			*prev;
}							t_dlist;

# define TO_END				1
# define TO_BEG				0

typedef struct				s_btree
{
	struct s_btree			*left;
	struct s_btree			*right;
	void					*data;
}							t_btree;

# define RIGHT				1
# define LEFT				0

int							ft_abs(int nb);
t_intmax					ft_absmax(t_intmax nb);
void						ft_arr_move_left_str(char **arr);
char						**ft_arrcat(char **a1, char **a2);
void						ft_arrdel(void ***tab);
char						*ft_arrglu(char **arg, char *separator,
								size_t size);
char						*ft_arrnglu(char **arg, char *separator,
								size_t size, size_t n);
void						ft_arriter_str(char **arr, void (*f)(char **));
size_t						ft_arrlen(void *a, size_t type);
char						**ft_arrstrcpy(char **src);
char						**ft_arrstrncpy(char **src, size_t n);
int							ft_atoi(const char *str);
size_t						ft_bitlen(t_uintmax p);
void						ft_btreedel(t_btree **r, void (*fun)(void *));
void						ft_btreemap(t_btree **root,
								void(*fun)(t_btree **t));
t_btree						*ft_btreenew(void *data);
void						ft_btree_add_parent(t_btree **r, t_btree *new,
								int side);
t_btree						*ft_btree_find_parent(t_btree *r, t_btree *tar);
void						ft_bzero(void *s, size_t n);
void						ft_dlstadd(t_dlist **alst, t_dlist *new);
void						ft_dlstdel(t_dlist **alst,
								void (*del)(void *, size_t), int tar);
size_t						ft_dlstlen(t_dlist *lst);
t_dlist						*ft_dlstnew(void const *content,
								size_t content_size);
pid_t						ft_fork(char *parent);
extern void					ft_free(void *ptr);
int							ft_isalpha(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isdigit(int c);
int							ft_islow(int c);
int							ft_isprint(int c);
int							ft_isup(int c);
char						*ft_itoa(int nb);
char						**ft_linesplit(char *s, char c);
void						ft_lstadd_top(t_list **alst, t_list *new);
void						ft_lstadd_end(t_list **alst, t_list *new);
void						ft_lstadd_sort(t_list **alst, t_list *new,
								int (*sfun)(void *, void *));
void						ft_lstdel(t_list **alst,
								void (*del)(void *, size_t));
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t						ft_lstlen(t_list *lst);
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list						*ft_lstnew(void const *content,
								size_t content_size);
char						**ft_lststrtotab(t_list *lst);
void						**ft_lsttotab(t_list *lst);
int							ft_max(int a, int b);
size_t						ft_maxst(size_t a, size_t b);
void						*ft_memalloc(size_t size);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						*ft_memccpy(void *dst, const void *src, int c,
								size_t n);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
void						ft_memdel(void **ap);
void						*ft_memmove(void *dst, const void *src, size_t len);
void						*ft_memset(void *b, int c, size_t len);
int							ft_min(int a, int b);
size_t						ft_minst(size_t a, size_t b);
void						ft_move_left(char *str);
size_t						ft_nbrlen(int nb);
size_t						ft_nbrlenbase(unsigned int nb, unsigned int base);
size_t						ft_nbrlenbasemax(t_uintmax nb, int base);
size_t						ft_nbrlenmax(t_intmax nb);
int							ft_open(char *path, int flag, char *parent);
int							ft_pow(int nb, int pow);
void						ft_putbtreestr(t_btree *root);
void						ft_putbtreearr(t_btree *root);
void						ft_putchar(char c);
void						ft_putchar_fd(char c, int fd);
void						ft_putendl(char const *s);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr(int n);
void						ft_putnbr_fd(int n, int fd);
void						ft_putnbrendl(int n);
void						ft_putnbrendl_fd(int n, int fd);
void						ft_putline(char *str);
void						ft_putstr(char const *s);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putstrarr(char **arr);
float						ft_sqrt(float nb);
char						*ft_stradd(char **s1, char const *s2);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strchr(const char *s, int c);
int							ft_strcloc(char c, char *ptr);
void						ft_strclr(char *s);
int							ft_strcmp(const char *s1, const char *s2);
char						*ft_strcpy(char *dst, const char *src);
void						ft_strdel(char **as);
int							ft_strequ(char const *s1, char const *s2);
int							ft_strinc(char **ptr, int size, char c);
char						*ft_strdup(const char *s1);
void						ft_strinschar(char **src, size_t pos, char c);
void						ft_strinsstr(char **src, char *cut, size_t pos);
void						ft_striter(char *s, void(*f)(char *));
void						ft_striteri(char *s,
								void (*f)(unsigned int, char *));
char						*ft_strjoin(char const *s1, char const *s2);
size_t						ft_strlcat(char *dst, const char *src, size_t size);
size_t						ft_strlen(const char *s);
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s,
								char (*f)(unsigned int, char));
char						*ft_strncat(char *s1, const char *s2, size_t n);
char						*ft_strncpy(char *dst, const char *src, size_t n);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
char						*ft_strndup(const char *s1, size_t n);
int							ft_strnequ(char const *s1, char const *s2,
								size_t n);
char						*ft_strnew(size_t size);
char						*ft_strnstr(const char *s1, const char *s2,
								size_t n);
char						*ft_strrchr(const char *s, int c);
void						ft_strremchar(char *src, size_t pos);
char						*ft_strrev(char *str);
char						*ft_strstr(const char *s1, const char *s2);
char						**ft_strsplit(char const *s, char c);
char						*ft_strsub(char const *s, unsigned int start,
								size_t len);
char						*ft_strtrim(char const *s);
size_t						ft_getlinesize(char *buf);
char						*ft_getlline(char *buf, int l);
int							ft_getnbrline(char *buf);
char						*ft_gotoline(char *buf, int l);
void						ft_swapchar(char *a, char *b);
void						ft_swapint(int *a, int *b);
int							ft_tolower(int c);
int							ft_toupper(int c);
size_t						ft_wordlen(char *str, char *seps);

/*
** GNL FUNCTIONS
*/

# define GNL_BUFF_SIZE 1

int							get_next_line(int const fd, char **line);

/*
** ERNNO ERROR MESSAGES FOR OPEN
*/

# define STR_EACCES "Permission denied"
# define STR_EDQUOT "Disk space full"
# define STR_EEXIST "The file already exist"
# define STR_EINVAL "Bad flag"
# define STR_EIO "I/O error"
# define STR_EISDIR "The patname given route to a directory"
# define STR_ELOOP "Too many symbolic links encountered in translating the p\
athname. Symbolic link loop suspected. OR O_NOFOLLOW is specified an\
d the file is a symbolic link"
# define STR_EMFILE "Too many file descriptor are already opened or the syst\
em file table is full"
# define STR_ENAMETOOLONG "The pathname is too long"
# define STR_ENOENT "O_CREAT is not set and the named file does not exist. O\
R a component of the path name does not exist"
# define STR_ENOSPC "Disk space full"
# define STR_ENOTDIR "A component of the path prefix is not a directory. OR t\
he path argument is not an absolute path and fd is nei\
ther AT_FDCWD nor a file descriptor associated with a directory."
# define STR_ENXIO "O_NONBLOCK and O_WRONLY are set, the file is a FIFO, an\
d no process has it open for reading"
# define STR_EOPNOTSUPP "O_SHLOCK or O_EXLOCK is specified, but the underlyin\
g filesystem does not support locking. OR an attempt is made to ope\
n a socket (not currently implemented)"
# define STR_EOVERFLOW "The named file is a regular file and its size does n\
ot fit in an object of type off_t."
# define STR_EROFS "The named file resides on a read-only file system, and t\
he file is to be modified."
# define STR_ETXTBSY "The file is a pure procedure (shared text) file that i\
s being executed and the open() call requests write access."
# define STR_EBADF "The path argument does not specify an absolute path and t\
he fd argument is neither AT_FDCWD nor a valid file descriptor open f\
or searching."

/*
** FOR FORK
*/

# define FORK_EAGAIN "The system-imposed limit on the total number of process\
es under execution would be exceeded.  This limit is configuration-dependent.\
OR The system-imposed limit MAXUPRC (<sys/param.h>) on the total number of pro\
cesses under execution by a single user would be exceeded."

# define FORK_ENOMEM "There is insufficient swap space for the new process."

#endif
