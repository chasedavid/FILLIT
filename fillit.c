/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/15 23:16:36 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void fillit(char **map, tet *alst, int size) // function 1
{

//win check
	printf("---- beginning of fillit ----\n");
//	printf("alst->alpha: %c \n", alst->alpha);
//	printf("alst->y: %d \n", alst->y);
	if (alst->next == NULL)
	{
		if (ft_place_tet(map, alst, size) != -1)
			return ;
		else
		{
			resetmap(map, size);
			alst = find_next_space(map, alst, size);
			fillit(map, alst, size);
		}
	}
	else if (alst->next == NULL && (alst->y >= size))
	{
		resetmap(map, size);
		alst->x = 0;
		alst->y = 0;
		fillit(map, alst, ++size);
	}
//find_next_space
	alst = find_next_space(map, alst, size);
//if place_piece fail
	if (ft_place_tet(map, alst, size) == -1)
	{
//	remove
		ft_remove(map, alst, size);
//	find next space
		alst = find_next_space(map, alst, size);
//	place_piece
		ft_place_tet(map, alst, size);
	}
	else 
		fillit(map, alst->next, size);
}
