/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/16 00:02:59 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
			printf("ft_placetet: return -1 \n");
			return (-1);
		}
		else
			map[row][col] = (char)(tet->alpha);
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
		k++;

		if (tmp[k] == '.')
		{
			col = MOVE_COL(col, size);
			row = MOVE_ROW(row, col);
			++k;
		}
		if (tmp[k] == '\n')
		{
			++row;
			col = tet->x;
			++k;
		}
		printf("ft_placetet: printing map \n");
		printmap(map, size);
	}
	printf("ft_placetet: return 0 \n");
	return (0);
}

void		ft_place_first(char **map, tet *tet, int size)
{
	int		k;
	int		col;
	int		row;

	k = 0;
	col = tet->x;
	row = tet->y;
	while ((tet->content)[k])
	{
		map[row][col] = (char)(tet->alpha);
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
		++k;
		if ((tet->content)[k] == '\n')
		{
			++row;
			++k;
		}
		if ((tet->content)[k] == '.')
		{
			col = MOVE_COL(col, size);
			row = MOVE_ROW(row, col);
			++k;
		}
	}
}
