/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/23 20:14:25 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_tet		*tetlist;
	int			size;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (-1);
	}
	tetlist = ft_memalloc(sizeof(t_tet));
	map.grid = NULL;
	map.size = 0;
	size = readtetfile(argv[1], &tetlist);
	if (size == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	trimpieces(tetlist);
	map.grid = makemap();
	map.size = ft_sqrt(4 * size);
	fillit(map, tetlist);
	return (0);
}
