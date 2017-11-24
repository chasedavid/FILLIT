/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/23 21:21:39 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>
#define DECLARE_STUFF int k; int y; int x; y = row; k = -1
#define DO_STUFF 	{	remove_tet(map, tet, row, col);	return (0);	}

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
	DECLARE_STUFF;
	if (((row + tet->y) >= map->size) || ((col + tet->x) >= map->size))
		return (0);
	while (y <= (row + tet->y))
	{
		x = col;
		while (x <= (col + tet->x))
		{
			while ((tet->content)[++k] != '\n')
			{
				if ((tet->content)[k] != '.')
				{
					if ((map->grid)[y][x] != '.')
						DO_STUFF;
					if ((map->grid)[y][x] == '.')
						(map->grid)[y][x] = tet->alpha;
				}
				++x;
			}
		}
		++y;
	}
	return (1);
}

int			place_on_map(t_map *map, t_tet *tet)
{
	int row;
	int col;

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
