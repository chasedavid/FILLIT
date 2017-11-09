/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:24 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/08 23:17:21 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# define MOVE_COL(a, b) ((++a >= b) ? 0 : a)
# define MOVE_ROW(a, b) ((b == 0) ? ++a : a)

char	*tettrim(char *str);
char	**trypiece(char **map, char *piece);
void	*ft_lstlastitem(t_list **alst);
void	checkpiece(t_list *link, char **map, int alpha);
int		check_buf(char *buf);
int		checkbufchar(char *buf);

int		arr2dlenrow(char **array2d);
int		arr2dlencol(char **array2d);

int		ft_sqrt(int n);
t_list	*find_next_space(char **map, t_list *tet, int size);
t_list	*tet_index(t_list *tet);
void	ft_removechar(char **map, t_list *tet, int size);
void	fillit(t_list **alst, int size);
int		ft_validmove(char **map, t_list *tet, int row, int col, int size);

#endif
