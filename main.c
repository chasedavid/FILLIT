/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:08 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 21:05:55 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h" 
#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	tet		*tetlist;
	char	**map; 
	int		size;

	tetlist = ft_memalloc(sizeof(tet));
	map = NULL;
	if (argc != 2) 
	{	
		ft_putstr("Error\n");
		return (-1);
	}
	size = readtetfile(argv[1], &tetlist);
	size = ft_sqrt(4 *size);
	map = makemap();
//		printf("\n------ start print initial list ----------\n");
		//ft_printlist(&tetlist);
//		printf("------ end print initial list ------------\n");

//		trimpieces(tetlist);

//		printf("\n------ start print list after ft_lstiter----------\n");
//		ft_printlist(&tetlist);
//		printf("------------------- end --------------------------\n");

//	fillit(&linked_list);
//	ft_printlist(&tetlist);
	printf("\n----- final map result ------ \n");
	printmap(map, size);
	return (0);
}
