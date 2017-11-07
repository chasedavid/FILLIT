/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/07 00:08:10 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int main(int argc, char **argv)
{
	t_list *tetlist;
	char **map; 
	int mapsize;
	t_coord xy; 

	tetlist = ft_memalloc(sizeof(t_list));
	map = NULL;
	mapsize = 0;
	xy.x = 0;
	xy.y = 0;
	if (argc != 2) 
		ft_putstr("Incorrect number of arguments \n");
	if (argc == 2)
	{
		readtetfile(argv[1], &tetlist);
		mapsize = mapsizemin(&tetlist);
		printf("main.c - mapsizemin result: %d \n", mapsize);
		map = makemap(mapsize);

		printf("\n------ start print initial list ----------\n");
		//ft_printlist(&tetlist);
		printf("------ end print initial list ------------\n");

		trimpieces(tetlist);
		//ft_lstiter(tetlist, trimpiece);

//		printf("\n------ start print list after ft_lstiter----------\n");
//		ft_printlist(&tetlist);
//		printf("------------------- end --------------------------\n");


		fillit(map, tetlist->next, xy, mapsize);
//		fillit(map, tetlist->next, xy, mapsize);
	}
//	fillit(&linked_list);
//	ft_printlist(&tetlist);
//	ft_printlistitem(tetlist->next);
	printf("\n----- final map result ------ \n");
	ft_print2d(map, mapsize);
	return (0);
}
