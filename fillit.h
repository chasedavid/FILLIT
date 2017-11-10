/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/09 18:48:52 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# define MOVE_COL(a, b) ((++a >= b) ? 0 : a)
# define MOVE_ROW(a, b) ((b == 0) ? ++a : a)

typedef struct		s_list
{
	void			*content;
	unsigned int	content_size;
	int				alpha;
	int				x;
	int				y;
	int				lst_i;
	struct s_list	*next;
}					tet;
//reading/ parsing functions
int		readtetfile(char *argv, tet **list);
tet		*ft_tetnew(void const *content, unsigned int content_size, int alpha, int list_i);
void	ft_tetappend(tet **alst, tet *new);

char	*tetrim(char *str);
//map functions
char	**makemap(void);
void	resetmap(char **map, int size);
void	printmap(char **map, int size);

char	**trypiece(char **map, char *piece);
void	*ft_lstlastitem(t_list **alst);
void	checkpiece(t_list *link, char **map, int alpha);
int		check_buf(char *buf);
int		checkbufchar(char *buf);

int		ft_sqrt(int n);
t_list	*find_next_space(char **map, t_list *tet, int size);
t_list	*tet_index(t_list *tet);
void	ft_removechar(char **map, t_list *tet, int size);
void	fillit(t_list **alst, int size);
int		ft_validmove(char **map, t_list *tet, int row, int col, int size);

#endif
