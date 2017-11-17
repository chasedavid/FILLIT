/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:10:42 by aho               #+#    #+#             */
/*   Updated: 2017/11/16 18:41:38 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void fillit(char **map, tet *alst, int size, coord xy) // function 1
{

//win check
	printf("---- beginning of fillit ----\n");
//	printf("alst->alpha: %c \n", alst->alpha);
//	printf("alst->y: %d \n", alst->y);


	//if pieces are still in list
	if (alst != NULL)
	{
//		xy = getnextxy(map, alst, size, xy);
		printf("xy.x: %d  /  xy.y: %d \n", xy.x, xy.y);
		if (placetet(map, alst, size, xy)) //tet is validly placed
		{
			fillit(map, alst->next, size, xy); //continue placing next tet
//			return (1);
		}
		else
		{
			printf("if unable to place tet, try the next spot and call fillit\n");
			//xy = skipxy(); //skip attempted xy and get the next xy
			//fillit(map, alst, size, xy);
			return (-1);
		}
		else 
		{
			//increase the mapsize and start over
			//resetmap();
			printf("make map bigger! \n");
		}
	}			

	else
	{
		printf("All pieces placed! Amazing! \n");
//		return (1);
	}

}
