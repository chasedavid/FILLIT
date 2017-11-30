/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/29 17:21:13 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUF_SIZE 20

typedef struct		s_tet
{
	char			*content;
	int				content_size;
	int				alpha;
	int				x;
	int				y;
	int				lst_i;
	struct s_tet	*next;
}					t_tet;

typedef struct		s_map
{
	char			**grid;
	int				size;
}					t_map;

int					readtetfile(char *argv, t_tet **list);
t_tet				*ft_tetnew(void *content, int tetsize, int alpha, int i);
void				ft_tetappend(t_tet **alst, t_tet *new);
void				ft_printtetlist(t_tet **alst);
int					validhashes(char *buf);
int					validchars(char *buf);
char				*ft_strsub_free(char *str, int col, int n);
char				*check_hash_num(char *s, int i);
void				trimpieces(t_tet *list);
char				*tettrim(char *str);
char				*t_deletecol(char *str, int col, int n);
char				*trimcols(char *str);
char				*trimrows(char *str);
char				**makemap(void);
void				printmap(char **map, int size);
int					ft_width(char *s);
int					ft_height(char *s);
int					ft_sqrt(int n);
void				remove_tet(t_map *map, t_tet *tet, int row, int col);
void				fillit(t_map *map, t_tet *tet);
int					place_tet(t_map *map, t_tet *tet, int row, int col);
int					place_on_map(t_map *map, t_tet *tet);

#endif
