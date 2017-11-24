/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:14:09 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/23 19:26:02 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char		**makemap(void)
{
	int		row;
	int		col;
	char	**map;

	row = 0;
	if (!(map = (char**)malloc((32 + 1) * sizeof(char*))))
		return (NULL);
	map[32] = 0;
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

void		printmap(char **map, int size)
{
	int		row;
	int		col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			ft_putchar(map[row][col++]);
		ft_putchar('\n');
		++row;
	}
}
