/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/08 11:21:17 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*int		iterate_j(int j, int min_n) //function1
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
	int 	row;
	int		col;

	col = tet->x;
	row = tet->y;
	while(map[row][col])
	{
		if (map[row][col] == tet->alpha)
			map[row][col] = '.';
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
	}
}

int		ft_validmove(char **map, t_list *tet, int row, int col, int size) // function4
{
	char	*tmp;
	int		k;

	tmp = tet->content;
	k = 0;
	while (tmp[k])	
	{
		if (map[row][col] != '.')
			return (-1);
		else
			map[row][col] = (char)(tet->alpha);
		col = MOVE_COL(col, size);
		row = MOVE_ROW(row, col);
		k++;
		if (tmp[k] == '\n')
		{
			row++;
			k++;
		}
	}
	return (0);
}
