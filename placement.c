/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/21 08:13:34 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void		ft_remove(char	**map, t_tet *tet, int size)
{
	int		row;
	int		col;
	int		k;

	col = tet->x;
	row = tet->y;
	k = 0;
	while((tet->content)[k] && map[row][col])
	{
		if (map[row][col] == tet->alpha)
			map[row][col] = '.';
		col = MOVE_COL(col, size); 
		row = MOVE_ROW(row, col);
		k++;
		if ((tet->content)[k] == '\n')
		{
			if (col != 0 )
				row++;
			col = tet->x;
			k++;
		}
	}
}

int			check_up_left(char **map, t_tet *tet, int row, int col)
{
	if (col == tet->x && row == tet->y)
		return (1);
	if (row ==  0)
		if (col == 0 || (map[row][col - 1] == (tet->alpha)))
			return (1);
	if (row != 0)
	{
		if (col == 0)
			if (map[row - 1][col] == (tet->alpha))
				return (1);
		if (col != 0)
			if (map[row][col - 1] == (tet->alpha) || map[row - 1][col] == (tet->alpha))
				return (1);
	}
	return (0);
}

int			ft_place_tet(char **map, t_tet *tet, int size)
{
	int		k;
	int		row;
	int		col;

	k = 0;
	row = tet->y;
	col = tet->x;

	while ((tet->content)[k] && col < size && row < size)
	{
		if ((tet->content)[k] == '.')
		{
			col = MOVE_COL(col, size);
			row = MOVE_ROW(row, col);
			++k;
		}
		if ((tet->content)[k] == '\n')
		{
			if (col != 0)
				++row;
			col = tet->x;
			++k;
		}
		if (map[row][col] != '.' || (check_up_left(map, tet, row, col) != 1))
		{
			printf("IF CHECK: %d", map[row][col] != '.');
			ft_remove(map, tet, size);
			return (-1);
		}
		else
		{
			map[row][col] = (char)(tet->alpha);
			col = MOVE_COL(col, size);
			row = MOVE_ROW(row, col);
			++k;
		}
		printmap(map, size);
	}
	ft_putstr("---End of placing tet---\n");
//	printmap(map, size);
	return (0);
}

char		**ft_place_first(char **map, t_tet *tet, int size)
{
	int		k;
	int		col;
	int		row;

	k = 0;
	col = tet->x;
	row = tet->y;
	while ((tet->content)[k])
	{
		if ((tet->content)[k] == '.')
		{
			col = MOVE_COL(col, size);
			row = MOVE_ROW(row, col);
			++k;
		}
		map[row][col] = (char)(tet->alpha);
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
		++k;
		if ((tet->content)[k] == '\n')
		{
			++row;
			col = tet->x;
			++k;
		}
	}
	return (map);
}

/*
int			place_on_map(char **map, t_tet tet, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (place_tet(map, tet, size))
				if (place_on_map(map, tet->next, int size))
					return (1);
				else
					remove_tet(map, tet, size);
			++col;
		}
		++row;
	}
	return (0);
}*/
