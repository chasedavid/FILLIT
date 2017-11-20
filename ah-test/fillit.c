/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_ah.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:10:42 by aho               #+#    #+#             */
/*   Updated: 2017/11/18 02:27:53 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int fillit(char **map, tet *alst, int size, coord xy) // function 1
{
	printf("---- fillit call ----\n");
	printf("alst->alpha: %c \n", alst->alpha);
	printf("alst->content:\n%s\n", alst->content);
	printf("xy.x: %d, xy.y: %d\n", xy.x, xy.y);
	printf("map:\n");
	printmap(map, size);

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
		else
		{
			printf("reaches else condition - I want to backtrack here \n");
			xy = skipxy(map, alst, size, xy);
			return (-1);
		}
	}
	return (1);
}
