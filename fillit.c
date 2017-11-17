/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/16 18:54:58 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void	fillit(char **map, tet *alst, int size, tet *startover) // function 1
{
	
//win check
	printf("---- beginning of fillit ----\n");
//	printf("alst->alpha: %c \n", alst->alpha);
//	printf("alst->y: %d \n", alst->y);
	if (alst->next == NULL)
	{
		//winning
		if (ft_place_tet(map, alst, size) != -1)
			return ;
		//++size
		else if ((alst->x + 1 == size) && (alst->y + 1 == size))
		{
			resetmap(map, size);
			++size;
			fillit((ft_place_first(map, startover, size)), startover->next, size, startover);
		}
		else
		{
			resetmap(map, size);
			fillit(map, startover, size, startover);
		}
	}
	else if (alst->next == NULL && (alst->y >= size))
	{
		resetmap(map, size);
		alst->x = 0;
		alst->y = 0;
		fillit(map, alst, ++size, startover);
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
		fillit(map, alst->next, size, startover);
}
