/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:03:04 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 22:06:19 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Macros
*/
# define BUFF_SIZE		4096
# define UN(val)		((void)(val));
# define NNB(x)			(x >= 0 ? x : -x)
# define SC(val)		ft_setcolor(val);
# define RC				ft_resetcolor();
# define PCN			ft_putchar('\n');
# define PC(val)		ft_putchar(val);
# define PCA(val)		PC(val) PCN
# define PS(val)		ft_putstr(val);
# define PSA(val)		PS(val) PCN
# define PN(val)		ft_putnbr(val);
# define B_HEX			"0123456789abcdef"
# define B_HEXM			"0123456789ABCDEF"
# define B_OCT			"01234567"

/*
** Standard File descriptors
*/
# define STDIN	0
# define STDOUT	1
# define STDERR	2

/*
** Typedefs
*/
typedef struct s_list	t_list;
typedef struct s_dlist	t_dlist;
typedef struct s_btree	t_btree;
typedef	void	(*t_tabf)(char *, void *);
typedef void	(*t_listf)(t_list *, void *);
typedef void	(*t_dlistf)(t_dlist *, void *);
typedef int		(*t_compar)(void *, size_t, void *, size_t);
typedef void	(*t_deleter)(void *, size_t);

/*
** Lists
*/
struct			s_list
{
	void		*content;
	size_t		content_size;
	t_list		*next;
};

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *list, void(*f)(t_list *elem));
void			ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstrev(t_list *lst);
void			ft_free_lst(t_list **list);
void			ft_lstpushback(t_list **begin, t_list *new);
size_t			ft_lstsize(t_list **list);
void			ft_lst_foreach(t_list *list, t_listf f, void *data);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** D_Lists
*/
struct			s_dlist
{
	void		*content;
	size_t		content_size;
	char		select;
	t_dlist		*next;
	t_dlist		*previous;
};

t_dlist			*ft_lstd_new(const void *content, size_t content_size);
void			ft_lstd_add(t_dlist **alst, t_dlist *new);
void			ft_lstd_pushback(t_dlist **begin, t_dlist *new);
size_t			ft_lstd_size(t_dlist **dlist);
void			ft_lstd_delone(t_dlist **dlist, t_dlist *ptr);
void			ft_lstd_foreach(t_dlist *dlist, t_dlistf f, void *data);
size_t			ft_get_maxsize(t_dlist *dlist);

/*
** Trees
*/
struct			s_btree
{
	t_btree		*right;
	t_btree		*left;
	void		*content;
	size_t		content_size;
};

t_btree			*ft_btree_new(void *content, size_t content_size);
void			ft_btree_insert(t_btree **root, t_btree *node, t_compar cmp);
void			ft_btree_del(t_btree **root, t_deleter del);
t_btree			*ft_btree_find(t_btree *node, void *n, size_t s, t_compar cmp);
t_btree			*ft_btree_delone(t_btree **r, void *n, size_t s, t_compar cmp);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
char			*ft_strtrim(const char *s);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			**ft_strsplit(const char *s, char c);
char			**ft_str_split(const char *s);
char			*ft_itoa(int n);
char			*ft_ltoa(long int n);
char			*ft_ltoa_base(long int n, char *base);
void			ft_setcolor(unsigned char color);
void			ft_resetcolor(void);
int				ft_strclen(const char *s1, char c);
int				ft_strsublen(const char *str, int start, char c);
char			*ft_utoa(size_t n);
char			*ft_utoa_base(size_t n, char *base);
char			*ft_ultoa(unsigned long n);
int				ft_recursive_power(int nb, int power);
char			*ft_itoa_base(size_t n, char *base);
int				ft_tablen(char **tab);
char			*ft_strunion(char **str_array, char c);
void			ft_free_tab(char **tab);
void			ft_tab_foreach(char **tab, t_tabf f, void *data);
size_t			ft_strccount(char *str, char c);
int				get_next_line(const int fd, char **line);

#endif
