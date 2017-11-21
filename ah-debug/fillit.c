/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:10:42 by aho               #+#    #+#             */
/*   Updated: 2017/11/20 23:39:29 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int fillit(char **map, tet *alst, int size, coord *xy) // function 1
{

//win check
	printf("---- fillit call ----\n");
	printf("alst->alpha: %c \n", alst->alpha);
	printf("alst->content:\n%s\n", alst->content);
	printf("xy->x: %d, xy->y: %d\n", xy->x, xy->y);
	printf("map:\n");
	printmap(map, size);
//	printf("alst->y: %d \n", alst->y);

	//1. WINNING CONDITION 
/*
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
*/
	if (alst->next != NULL)
	{
/*
		if (fillit(map, alst->next, size, xy) == -1) 
		{
			map = removepiece(map, alst, size, xy);
			xy = skipxy(map, alst, size, xy);
		}
*/
	 	if (placetet(map, alst, size, xy) == 1)
		{
			if (alst->next == NULL)
			{
				printf("this is the end!! ");
				return (1);
			}
			//if the next piece fails...
			if (fillit(map, alst->next, size, xy) == -1)
			{
				printf("fillit failed! remove the piece \n");
				printf("xy->x: %d, xy->y: %d \n", xy->x, xy->y);
				map = removepiece(map, alst, size, xy);
				xy = skipxy(map, alst, size, xy);
				printf("after skipxy: xy->x - %d , xy->y - %d \n", xy->x, xy->y);
//				placetet(map, alst, size, xy);
//				return (-1);
//				return fillit(map, alst, size, xy);
			}

//			xy = getnextxy(map, alst, size, xy);
			return fillit(map, alst->next, size, xy);
		}
		else
		{
			printf("unable to place the tet... \n");
			return (-1);
		}
	}
	return (1);
}
