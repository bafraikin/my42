/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bafraiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:33:39 by bafraiki          #+#    #+#             */
/*   Updated: 2018/12/03 11:40:46 by bafraiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strnew(size_t size);
t_list				*ft_list_find(t_list *begin_list,
		void *data_ref, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*del)());
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lst_add_cont(void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_list_add_back(t_list **begin_list, void *content,
		size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
char				**ft_strsplit(char const *s, char c);
int					ft_atoi(const char *str);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_strclr(char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
int					ft_isdigit(int c);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **ap);
int					ft_isalnum(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memalloc(size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);

t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
void				ft_swapptr(void **a, void **b);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_push_back(t_list **begin_list,
		void *content, size_t content_size);

#endif
