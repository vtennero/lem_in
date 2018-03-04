/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:25:20 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/19 11:25:08 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 4

# include "libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*parent;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *litl, size_t len);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strclr(char *s);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
void				*ft_bzero(void *b, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, int n);
char				*ft_strjoin_clr(char *a, char *b, int d);
int					ft_char_pos(char *str, char c);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(char const *s);
int					ft_atoi(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
int					ft_abs(int n);
long long			ft_abs_ll(long long n);
int					ft_max(size_t n, size_t p);
int					ft_min(size_t n, size_t p);
int					ft_wcharlen(wchar_t c);
int					ft_wcharlen(wchar_t c);
int					ft_wstrlen(wchar_t *wstr);
int					ft_eq_char(char c1, char c2);
int					get_next_line(int const fd, char **line);
/*
** ------------------------- LISTS -------------------------
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstpush(t_list *lst, t_list *elem);
t_list				*ft_lstend(t_list *lst);
/*
** ------------------------- MEMORY MANIPULATION -------------------------
*/
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memdup(const void *s, size_t n);
/*
** ------------------------- ITOA & ALII -------------------------
*/
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_lutoa(unsigned long n);
char				*ft_lltoa(long long n);
char				*ft_llutoa(unsigned long long n);
char				*ft_itoa_base(int n, const char *base);
char				*ft_ltoa_base(long n, const char *base);
char				*ft_lutoa_base(unsigned long n, const char *base);
char				*ft_lltoa_base(long long n, const char *base);
char				*ft_llutoa_base(unsigned long long n, const char *base);
/*
** ------------------------- DECIMAL LENGTH -------------------------
*/
int					ft_intlen(int n);
int					ft_longlen(long n);
int					ft_ulonglen(unsigned long n);
int					ft_llonglen(long long n);
int					ft_ullonglen(unsigned long long n);

#endif
