/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:42:26 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/08 11:45:22 by cfarnswo         ###   ########.fr       */
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

void	ft_removechar(char	**map, t_list *tet, int min_n, int i, int j) // function3
{
	while(map[i][j])
	{
		if (map[i][j] == tet->alpha)
			map[i][j] = '.';
		j = iterate_j(j, min_n);
		i = iterate_i(i, j);
	}
}

int		ft_validmove(char **map, t_list *tet, int i, int j, int min_n) // function4
{
	char	*tmp;
	int		k;

	tmp = tet->content;
	k = 0;
	tet = find_next_space(map, tet, min_n, i, j);
	i = tet->y;
	j = tet->x;
	while (tmp[k])	
	{
		if (map[i][j] != '.')
		{
			ft_removechar(map, tet, min_n, tet->y, tet->x);
			return (-1);
		}
		else
			map[i][j] = (char)(tet->alpha);
		j = iterate_j(j, min_n);
		i = iterate_i(i, j);
		k++;
		if (tmp[k] == '\n')
		{
			i++;
			k++;
		}
	}
	return (0);
}
