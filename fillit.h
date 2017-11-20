/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/18 17:27:53 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# define MOVE_COL(a, b) ((++a >= b) ? 0 : a)
# define MOVE_ROW(a, b) ((b == 0) ? ++a : a)

typedef struct		s_tet
{
	char			*content;
	unsigned int	content_size;
	int				alpha;
	int				x;
	int				y;
	int				lst_i;
	struct s_tet	*next;
}					t_tet;

//reading/ parsing functions
int		readtetfile(char *argv, t_tet **list);
t_tet	*ft_tetnew(void const *content, unsigned int content_size, int alpha, int list_i);
void	ft_tetappend(t_tet **alst, t_tet *new);
void 	ft_printtetlist(t_tet **alst);
int		validhashes(char *buf);
int     validchars(char *buf);

//trimming functions
char	*ft_strsub_free(char *str, int col, int n);
void	trimpieces(t_tet *list);
char	*tettrim(char *str);
char    *t_deletecol(char *str, int col, int n);
char	*trimcols(char *str);
char	*trimrows(char *str);


char	*tetrim(char *str);
//map functions
char	**makemap(void);
void	resetmap(char **map, int size);
void	printmap(char **map, int size);

char	**trypiece(char **map, char *piece);
//void	*ft_lstlastitem(t_list **alst);

int		ft_sqrt(int n);
t_tet		*find_next_space(char **map, t_tet *tet, int size);
void	ft_remove(char **map, t_tet *tet, int size);
void	fillit(char **map, t_tet *alst, int size, t_tet *startover);
int		ft_place_tet(char **map, t_tet *tet, int size);
char	**ft_place_first(char **map, t_tet *tet, int size);
int		check_up_left(char **map, t_tet *tet, int row, int col);
#endif
