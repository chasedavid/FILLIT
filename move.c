/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:09:50 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/08 23:09:39 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*find_next_space(char **map, t_list *tet, int size)
{
	int 	row;
	int 	col;

	col = tet->x;
	row = tet->y;
	while (map[row][col] != '.')
	{
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
	}
	if (tet->x == row && tet->y == col)
	{
		tet->x = MOVE_COL(col, size);
		tet->y = MOVE_ROW(row, col);
	}
	else
	{
		tet->x = col;
		tet->y = row;
	}
	return (tet);
}

t_list		*tet_index(t_list *tet)
{
	tet->next->x = tet->x;
	tet->next->y = tet->y;
	return (tet->next);
}

