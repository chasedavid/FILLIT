/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/09 11:31:45 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
include "fillit.h"
#include <stdio.h>

char **makemap(int n) // function3
{

	char **map;
	int i;
	int j;
	
	i = 0;
	if (!(map = (char**)malloc((n + 1) * sizeof(char*)))) 
		return (NULL);
	map[n + 1] = 0;
	while (i < n)
	{
		map[i] = ft_memalloc(n + 1);
		j = 0; 
		while (j < n)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	return (map); 
}

void fillit(t_list **alst, int size) // function 1
{

//make map(pass map in)
//win check
//find_next_space
//if place_piece fail
//	remove
//	find next space
//	place_piece
//else 
//	fillit(map, tet_index(tet))
	
	char **map;
	int mapsize;
	t_list *current; //this is the current piece

	t_list *last; 
	last = ft_lstlastitem(alst);
	ft_lstsize(last);

	mapsize = min_n; // technically sqrt(4 * lst_size)
	map = makemap(mapsize);

	ft_validmove(map, *alst, 0, 0, size);

	int i;
	i = 0;
	while (map[i]) 
	{
		printf("%s\n", map[i]);
		++i;
	}


//	ft_printlist(alst);
	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, map, checkpiece);


	//once all pieces have been placed, print grid to show solution


}
