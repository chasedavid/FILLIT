/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:10:42 by aho               #+#    #+#             */
/*   Updated: 2017/11/18 00:53:40 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int fillit(char **map, tet *alst, int size, coord xy) // function 1
{

//win check
	printf("---- fillit call ----\n");
	printf("alst->alpha: %c \n", alst->alpha);
	printf("alst->content:\n%s\n", alst->content);
	printf("xy.x: %d, xy.y: %d\n", xy.x, xy.y);
	printf("map:\n");
	printmap(map, size);

//	
//	printf("alst->y: %d \n", alst->y);


	//1. WINNING CONDITION 
	if (alst->next == NULL)
	{
		if (placetet(map, alst, size, xy) == 1)
		{
			printf("We win!! \n");
			return (1);
		}
		else
		{
			printf("time to make the map bigger \n");
			return (-1);
		}
	}

	while (alst->next != NULL)
	{
		if (placetet(map, alst, size, xy) == 1)
			return fillit(map, alst->next, size, xy);
//		else if (getnextxy == 1) 
//			return fillit(map, alst->next, size, xy);
		else
		{
//			biggermap();
//			getheadoflist();
//			return fillit(map, alst, size, xy);
			printf("reaches else condition \n");
			xy = skipxy(map, alst, size, xy);
			return (-1);
		}
	}


	


/*
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
*/
	return (1);
}
