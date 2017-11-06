/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 01:43:41 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 01:27:06 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t num);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int num);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int num, int fd);
int					ft_isspace(int c);
int					ft_signofnumstr(char const *str);
int					ft_powerofnum(int n);
int					ft_wordlen(char const *s, char c);
int					ft_wordcount(char const *s, char c);
int					check_int(long int num);
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	int 			alpha;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_coord
{
	int 			x;
	int				y;
}					t_coord;

t_list				*ft_lstnew(void const *content, size_t content_size, int alpha);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void ft_printlist(t_list **alst);
void    ft_lstappend(t_list **alst, t_list *new);
int check_buf(char *buf);
int checkbufchar(char *buf);
int isvalidpiece(char *buf);

int fillit(char **map, t_list *piece, t_coord xy, int mapsize);

void checkpiece(t_list *link, char **map, int alpha);

void trimpiece(t_list *link);
void    ft_lstiter(t_list *lst, void (*f)(t_list *elem));

char *tettrim_str(char *str);
char **trypiece(char **map, char *piece);

int arr2dlenrow(char **array2d);
int arr2dlencol(char **array2d);


t_coord getnextxy(char **map, char *piece, int mapsize);
int piecewidth(char *piece);
int maprowavails(char *row);
char **placexy(char **map, char *piece, int alpha, t_coord xy);
int checkxy(char **map, char *piece, t_coord xy);

int readtetfile(char *argv, t_list **list);
void ft_print2d(char **array2d, int rows);
void ft_printlistitem(t_list *item);
char **makemap(int n);

#endif
