/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 18:38:29 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include "fillit.h"

int main(int argc, char **argv)
{
	tet		*tetlist;
	char	**map; 
	int		size;

	tetlist = ft_memalloc(sizeof(tet));
	map = NULL;
	mapsize = 0;
	if (argc != 2) 
		ft_putstr("Error\n");
	if (argc == 2)
	{
		if ((size = readtetfile(argv[1], &tetlist)) < 0);
			return (-1);	
		size = ft_sqrt(4 *size);
		map = makemap(void);
//		printf("\n------ start print initial list ----------\n");
		//ft_printlist(&tetlist);
//		printf("------ end print initial list ------------\n");

//		trimpieces(tetlist);
		//ft_lstiter(tetlist, trimpiece);

//		printf("\n------ start print list after ft_lstiter----------\n");
//		ft_printlist(&tetlist);
//		printf("------------------- end --------------------------\n");


//		fillit(map, tetlist->next, xy, mapsize);
//		fillit(map, tetlist->next, xy, mapsize);
	}
//	fillit(&linked_list);
//	ft_printlist(&tetlist);
//	ft_printlistitem(tetlist->next);
	printf("\n----- final map result ------ \n");
	printmap(map, size);
	return (0);
}
