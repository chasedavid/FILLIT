/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:22 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 00:37:01 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
/*
void fillit(t_list **alst)
{
	char **map;
	int mapsize;
	t_list *current; //this is the current piece
//	t_coord xy;

	mapsize = 5; // technically sqrt(4 * lst_size)
	map = makemap(mapsize);
*/
/*
//  HARDCODED MAP
	char *hardcodestring = "CCBAA\nCBBBA\nC...A\n.....\n.....\n";
	char **hardcodemap = ft_strsplit(hardcodestring, '\n');

	int i;
	i = 0;
	while (i < 5) 
	{
		printf("hardcode map[%i]: %s \n", i, hardcodemap[i]);
		i++;
	}
*/
//	printf("\n >>>> arr2dlenrow: %d \n", arr2dlenrow(map));
//	printf("\n >>>> arr2dlencol: %d \n", arr2dlencol(map));	

//	if (map[1][3] == '\0') 
//		printf("map[1][3]: %c equals null terminator\n", map[1][3]);

//	current = *alst;
//	xy = getnextxy(map, tettrim_str(current->next->content), mapsize);

/*
	char *piece; 
	piece = tettrim_str(current->next->content);


	xy = getnextxy(hardcodemap, piece, 5);
	printf("fillit() ----- xy->x: %d \n", xy.x);
	printf("fillit() ----- xy->y: %d \n", xy.y);

	printf("checkxy result: %d \n", checkxy(hardcodemap, piece, xy));

	if (checkxy(hardcodemap, piece, xy) == 1) 
		hardcodemap = placexy(hardcodemap, piece, 'F', xy);
	if (checkxy(hardcodemap, piece, xy) == -1)



//	ft_printlist(alst);
	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, map, checkpiece);


	//once all pieces have been placed, print grid to show solution


	int i;
	i = 0;
	while (i < 5)
	{
		printf("final map[%i]: %s \n", i, map[i]);
		i++;
	}


}
*/
