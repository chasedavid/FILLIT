/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/18 15:53:18 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h" 
#include "fillit.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_tet		*tetlist;
	t_tet		*startover;
	char	**map; 
	int		size;

	size = 0;
	tetlist = ft_memalloc(sizeof(t_tet));
	map = NULL;
	if (argc != 2) 
	{	
		ft_putstr("error\n");
		return (-1);
	}
	size = readtetfile(argv[1], &tetlist);
	if (size == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	size = ft_sqrt(4 *size);
	map = makemap();
	trimpieces(tetlist);
	startover = tetlist;
	printf("\n------ print list after trimming pieces ----------\n");
	ft_printtetlist(&tetlist);
	printf("----------------------------------------------------\n");

	//ft_place_first(map, tetlist, size);
	fillit(ft_place_first(map, tetlist, size), tetlist->next, size, startover);
	
	ft_putstr("\n----- final map result ------ \n");
	ft_putnbr(size);
	ft_putchar('\n');
	printmap(map, size);
	return (0);
}
