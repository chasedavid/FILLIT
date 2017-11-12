/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:14:09 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/11 16:47:30 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**makemap(void)
{
	char	**map;
	int		row;
	int		col;

	row = 0;
	if (!(map = (char**)malloc((32 + 1) * sizeof(char*))))
		return (NULL);
	map[32 + 1] = 0;
	while (row < 32)
	{
		map[row] = ft_memalloc(32 + 1);
		col = 0;
		while (col < 32)
			map[row][col++] = '.';
		map[row][col] = '\0';
		++row;
	}
	return (map);
}

void		resetmap(char **map, int size)
{
	int		row;
	int		col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] = '.';
		++row;
	}
}

void		printmap(char **map, int size)
{
	int		row;
	int		i;

	row = 0;
	while (row < size)
	{
		i = 0;
		while (i < size)
			ft_putchar(map[row][i++]);
		ft_putchar('\n');
		row++;
	}
}

