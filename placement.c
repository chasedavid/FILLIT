/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/23 00:09:42 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdio.h>

void		remove_tet(char	**map, t_tet *tet, int row, int col)
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
  			if (map[y][x] == (tet->alpha))
  				map[y][x] = '.';
  			++x;
  		}
  	++y;
  	}
/* 
	while((tet->content)[k])
	{
		while ((tet->content)[k] == '.')
		{
			x = ((++x > = size) ? col : x);
			y = ((x == col) ? ++y : y);
			++k;
		}
		if (map[y][x] == tet->alpha)
		{
			map[y][x] = '.';
			x = ((++x > = size) ? col : x);
			y = ((x == col) ? ++y : y);
			++k;
		}
		else
		{
			x = ((++x > = size) ? col : x);
			y = ((x == col) ? ++y : y);
			++k;
		}
		if ((tet->content)[k] == '\n')
		{
			++y;
			x = col;
			++k;
		}
	}
}
*/
}



int			place_tet(char **map, t_tet *tet, int size, int row, int col)
{
	int		k;
	int		y;
	int		x;

	y = row;
	k = 0;
	if (((row + tet->y) >= size) || ((col + tet->x) >= size))
		return (0);
	while (y <= (row + tet->y))
	{
		x = col;
		while (x <= (col + tet->x))
		{
			while ((tet->content)[k] != '\n')
			{
				if ((tet->content)[k] != '.')
				{
					if (map[y][x] != '.')
					{
						remove_tet(map, tet, row, col);
						return (0);
					}
					if (map[y][x] == '.')
					{
						map[y][x] = tet->alpha;
					}
				}
				++x;
				++k;
			}
			++k;
		}
		++y;
	}
	return (1);
}

int			place_on_map(char **map, t_tet *tet, int size)
{
	int row;
	int col;

	if (tet == NULL)
		return (1);
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (place_tet(map, tet, size, row, col))
			{
				if (place_on_map(map, tet->next, size))
					return (1);
				remove_tet(map, tet, row, col);
			}
			++col;
		}
		++row;
	}
	return (0);
}
