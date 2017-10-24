/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:46:12 by nmougino          #+#    #+#             */
/*   Updated: 2017/10/24 23:02:10 by nmougino         ###   ########.fr       */
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
	struct s_btree			*parent;
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
void						ft_btree_add(t_btree *new,
								t_btree *parent, int side);
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
void						ft_lstrem(t_list **lst, t_list *tar,
								void (*del)(void *, size_t));
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
int							ft_open(char *path, int flag, int perm,
								char *parent);
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
size_t						ft_wordlen(char *str, int (*f)(char c));

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
# define STR_ELOOP_1 "Too many symbolic links encountered in translating the pa"
# define STR_ELOOP_2 "thname. Symbolic link loop suspected. OR O_NOFOLLOW is sp"
# define STR_ELOOP_3 "ecified and the file is a symbolic link"
# define STR_ELOOP STR_ELOOP_1 STR_ELOOP_2 STR_ELOOP_3
# define STR_EMFILE_1 "Too many file descriptor are already opened or the syst"
# define STR_EMFILE STR_EMFILE_1 "em file table is full"
# define STR_ENAMETOOLONG "The pathname is too long"
# define STR_ENOENT_1 "O_CREAT is not set and the named file does not exist. O"
# define STR_ENOENT_2 "R a component of the path name does not exist"
# define STR_ENOENT STR_ENOENT_1 STR_ENOENT_2
# define STR_ENOSPC "Disk space full"
# define STR_ENOTDIR_1 "A component of the path prefix is not a directory. OR t"
# define STR_ENOTDIR_2 "he path argument is not an absolute path and fd is neit"
# define STR_ENOTDIR_3 "her AT_FDCWD nor a file descriptor associated with a di"
# define STR_ENOTDIR STR_ENOTDIR_1 STR_ENOTDIR_2 STR_ENOTDIR_3 "rectory."
# define STR_ENXIO_1 "O_NONBLOCK and O_WRONLY are set, the file is a FIFO, and "
# define STR_ENXIO STR_ENXIO_1 "no process has it open for reading"
# define STR_EOPNOTSUPP_1 "O_SHLOCK or O_EXLOCK is specified, but the underlyin"
# define STR_EOPNOTSUPP_2 "g filesystem does not support locking. OR an attempt"
# define STR_EOPNOTSUPP_3 " is made to open a socket (not currently implemented"
# define STR_EOPNOTSUPP STR_EOPNOTSUPP_1 STR_EOPNOTSUPP_2 STR_EOPNOTSUPP_3 ")"
# define STR_EOVERFLOW_1 "The named file is a regular file and its size does no"
# define STR_EOVERFLOW STR_EOVERFLOW_1 "t fit in an object of type off_t."
# define STR_EROFS_1 "The named file resides on a read-only file system, and th"
# define STR_EROFS STR_EROFS_1 "e file is to be modified."
# define STR_ETXTBSY_1 "The file is a pure procedure (shared text) file that is"
# define STR_ETXTBSY_2 " being executed and the open() call requests write acce"
# define STR_ETXTBSY STR_ETXTBSY_1 STR_ETXTBSY_2 "ss."
# define STR_EBADF_1 "The path argument does not specify an absolute path and t"
# define STR_EBADF_2 "he fd argument is neither AT_FDCWD nor a valid file descr"
# define STR_EBADF STR_EBADF_1 STR_EBADF_2 "iptor open for searching."

/*
** FOR FORK
*/

# define FORK_EAGAIN_1 "The system-imposed limit on the total number of process"
# define FORK_EAGAIN_2 "es under execution would be exceeded.  This limit is co"
# define FORK_EAGAIN_3 "nfiguration-dependent. OR The system-imposed limit MAXU"
# define FORK_EAGAIN_4 "PRC (<sys/param.h>) on the total number of processes un"
# define FORK_EAGAIN_5 "der execution by a single user would be exceeded."
# define FORK_EAGAIN_6 FORK_EAGAIN_1 FORK_EAGAIN_2 FORK_EAGAIN_3 FORK_EAGAIN_4
# define FORK_EAGAIN FORK_EAGAIN_6 FORK_EAGAIN_5
# define FORK_ENOMEM "There is insufficient swap space for the new process."

#endif
