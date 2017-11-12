/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/11 18:55:37 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_remove(char	**map, tet *tet, int size)
{
	char	*tmp;
	int		row;
	int		col;
	int		k;

	tmp = tet->content;
	col = tet->x;
	row = tet->y;
	k = 0;
	while(tmp[k] && map[row][col])
	{
		if (map[row][col] == tet->alpha)
			map[row][col] = '.';
		col = MOVE_COL(col, size); 
		row = MOVE_ROW(row, col);
		k++;
		if (tmp[k] == '\n')
		{
			row++;
			col = tet->x;
			k++;
		}
	}
}

int			ft_place_tet(char **map, tet *tet, int size)
{
	char	*tmp;
	int		k;
	int		row;
	int		col;

	tmp = tet->content;
	k = 0;
	row = tet->y;
	col = tet->x;
	while (tmp[k])	
	{
		if (map[row][col] != '.')
		{
			ft_remove(map, tet, size);
			return (-1);
		}
		else
			map[row][col] = (char)(tet->alpha);
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
		k++;
		if (tmp[k] == '\n')
		{
			row++;
			col = tet->x;
			k++;
		}
	}
	return (0);
}
