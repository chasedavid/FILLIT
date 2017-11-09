/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/09 01:03:43 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
int		iterate_j(int j, int min_n) //function1
	{
		if (++j >= min_n)
			return (0);
		else
			return (j);
	}

int		iterate_i(int i, int j) //function2
{
	if (j == 0)
	{
		i++;
		return (i);
	}
	return (i);
}
*/

void	ft_removechar(char	**map, t_list *tet, int size) // function3
{
	char	*tmp
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

int		ft_validmove(char **map, t_list *tet, int size) // function4
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
		if (map[i][j] != '.')
		{
			ft_removechar(map, tet, size);
			return (-1);
		}
		else
			map[i][j] = (char)(tet->alpha);
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
