/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 01:29:54 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int main(int argc, char **argv)
{
	t_list *tetlist;
	char **map; 
	int mapsize;
	t_coord xy; 

	mapsize = 5;
	tetlist = ft_memalloc(sizeof(t_list));
	map = makemap(mapsize);
	xy.x = 0;
	xy.y = 0;
	if (argc == 2)
	{
		readtetfile(argv[1], &tetlist);
		ft_lstiter(tetlist, trimpiece);
		fillit(map, tetlist->next, xy, mapsize);
	}
	if (argc != 2) 
		ft_putstr("Incorrect number of arguments \n");

//	fillit(&linked_list);
//	ft_printlist(&tetlist);
//	ft_printlistitem(tetlist->next);
	printf("\n----- final map result ------ \n");
	ft_print2d(map, mapsize);
	return (0);
}
