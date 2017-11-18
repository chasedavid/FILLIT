/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/18 01:37:45 by aho              ###   ########.fr       */
/*   Updated: 2017/11/16 18:44:36 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# define MOVE_COL(a, b) ((++a >= b) ? 0 : a)
# define MOVE_ROW(a, b) ((b == 0) ? ++a : a)

typedef struct		tet
{
	char			*content;
	unsigned int	content_size;
	int				alpha;
	int				x;
	int				y;
	int				lst_i;
	struct tet		*next;
}					tet;

typedef struct		coord
{
	int				x;
	int				y;
}					coord;

//reading/ parsing functions
int		readtetfile(char *argv, tet **list);
tet		*ft_tetnew(void const *content, unsigned int content_size, int alpha, int list_i);
void	ft_tetappend(tet **alst, tet *new);
void 	ft_printtetlist(tet **alst);
int		validhashes(char *buf);
int     validchars(char *buf);

//trimming functions
char	*ft_strsub_free(char *str, int col, int n);
void	trimpieces(tet *list);
char	*tettrim(char *str);
char    *t_deletecol(char *str, int col, int n);
char	*trimcols(char *str);
char	*trimrows(char *str);
char	*tetrim(char *str);

//map placing functions 
int		placetet(char **map, tet *tetr, int size, coord xy);
coord   getnextxy(char **map, tet *tetr, int size, coord xy);
coord   skipxy(char **map, tet *tetr, int size, coord xy);
int		validmove(char **map, tet *tetr, int size, coord xy);
int		checkxy(char **map, tet *tetr, int size, coord xy);
char	**placexy(char **map, tet *tetr, coord xy);
int		firstrowpieces(char *piece);
int		maprowavails(char *row, int size, coord xy);

//map functions
char	**makemap(void);
void	resetmap(char **map, int size);
void	printmap(char **map, int size);

char	**trypiece(char **map, char *piece);
//void	*ft_lstlastitem(t_list **alst);

int		ft_sqrt(int n);
tet		*find_next_space(char **map, tet *tet, int size);
void	ft_remove(char **map, tet *tet, int size);
//void	fillit(char **map, tet *alst, int size, tet *startover);
int		fillit(char **map, tet *alst, int size, coord xy);

int		ft_place_tet(char **map, tet *tet, int size);
char	**ft_place_first(char **map, tet *tet, int size);
#endif
