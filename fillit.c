/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/08 11:16:41 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
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
/*
int ft_lstsize(t_list *last) // function2
{
	int num;

	num = (last->alpha) - 64;	
	printf("lstsize: %d \n", num);
	return (num);
}
*/
int		ft_sqrt(int n)
{
	int		i;

	i = 1;
	while (i)
	{
		if ((i * i) >= n)
			return (i);
		++i;
	}
	return (0);
}

//find first available space functions
t_list		*find_next_space(char **map, t_list *tet, int size)
{
	int		i;
	int		j;

	i = tet->x;
	j = tet->y;
	while (map[i][j] != '.')
	{
		j = MOVE_COL(j, size);
		i = MOVE_ROW(i, j);
	}
	if (tet->x == j && tet->y == i)
	{
		tet->x = MOVE_COL(j, size);
		tet->y = MOVE_ROW(i, j);
	}
	else
	{
		tet->x = j;
		tet->y = i;
	}
	return (tet);
}

void fillit(t_list **alst, int size) // function 1
{
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
