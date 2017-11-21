/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 03:26:13 by aho               #+#    #+#             */
/*   Updated: 2017/11/20 23:50:10 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

char **removelastalpha(char **map, int alpha, int size, coord *xy)
{
	printf("inside removelastalpha -- \n");
	printf("removing alpha: %c \n", alpha);
//	printf("beginning xy->x: %d, xy->y: %d  \n", xy->x, xy->y);

	while (xy->x < size)
	{
//		printf("xy->x: %d, xy->y: %d  \n", xy->x, xy->y);

		if (map[xy->x][xy->y] == alpha && xy->y < size)
		{
//			printf("removing xy->x: %d, xy->y: %d  \n", xy->x, xy->y);
			map[xy->x][xy->y] = '.';
		}
		if (xy->y >= size) 
		{	
			xy->y = 0;
			xy->x++;
		}
		else
			xy->y++;
	}
	return (map);
}





char **removepiece(char **map, tet *tetr, int size, coord *xy)
{
	printf("----- inside removelastpiece ---- \n");
	printf("tetr->alpha: %c\n", tetr->alpha);
	printf("tetr->content:\n%s\n", tetr->content);
	printf("xy->x: %d, xy->y: %d \n", xy->x, xy->y);

	printf("size: %d \n", size);
	printf("----- map before removelastalpha ---- \n");
	map = removelastalpha(map, tetr->alpha, size, xy);

	printf("----- map after removelastalpha ---- \n");
	printmap(map, size);


	return (map); 
}
