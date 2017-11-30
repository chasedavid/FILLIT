/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/28 13:57:41 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		remove_tet(t_map *map, t_tet *tet, int row, int col)
{
	int		y;
	int		x;
	int		k;

	y = row;
	k = 0;
	while (y <= (row + tet->y))
	{
		x = col;
		while (x <= (col + tet->x))
		{
			if ((map->grid)[y][x] == (tet->alpha))
				(map->grid)[y][x] = '.';
			++x;
		}
		++y;
	}
}

int			place_tet(t_map *map, t_tet *tet, int row, int col)
{
	int		k;
	int		y;
	int		x;

	y = row - 1;
	k = -1;
	if (((row + tet->y) >= map->size) || ((col + tet->x) >= map->size))
		return (0);
	while (++y <= (row + tet->y))
	{
		x = col - 1;
		while ((tet->content)[++k] != '\n' && ++x <= (col + tet->x))
		{
			if ((tet->content)[k] != '.' && (map->grid)[y][x] != '.')
			{
				remove_tet(map, tet, row, col);
				return (0);
			}
			else if ((tet->content)[k] != '.')
				(map->grid)[y][x] = tet->alpha;
		}
	}
	return (1);
}

int			place_on_map(t_map *map, t_tet *tet)
{
	int		row;
	int		col;

	if (tet == NULL)
		return (1);
	row = 0;
	while (row < map->size)
	{
		col = 0;
		while (col < map->size)
		{
			if (place_tet(map, tet, row, col))
			{
				if (place_on_map(map, tet->next))
					return (1);
				remove_tet(map, tet, row, col);
			}
			++col;
		}
		++row;
	}
	return (0);
}
