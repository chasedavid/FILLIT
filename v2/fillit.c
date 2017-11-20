/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:22 by aho               #+#    #+#             */
/*   Updated: 2017/11/16 02:08:52 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int fillit(char **map, t_list *piece, t_coord xy, int mapsize)
{
	printf("\n--------- fillit() called---------- \n");
//	printf("piece->alpha: %c\n", piece->alpha);
//	printf("piece->content:\n%s\n", piece->content);







//	xy = getnextxy(map, piece->content, mapsize);

	//print xy
//	printf("xy.x = %d \n", xy.x);
//	printf("xy.y = %d \n", xy.y);
	if (piece == NULL) 
	{
		printf("All pieces placed! Amazing! \n");
		return (1);
	}

	// check the valid spot
	// if piece can be placed in spot, mark as part of solution and continue to check all pieces

/*	
	if (validmove(map, piece, xy)) 
	{
		if (fillit(map, piece->next, xy, mapsize))
			return (1);
	}
	else 
	{
		//try the current piece in the next spot
		xy = nextspot;
		fillit(map, piece, xy, mapsize);
	}

	if (validmove(map, piece, xy) == -1)

*/



	if (checkxy(map, piece->content, xy) == 1) 
	{
		printf("xy before placexy [%d, %d] \n", xy.x, xy.y);
		placexy(map, piece->content, piece->alpha, xy);
		xy = getnextxy(map, piece->content, mapsize);
		printf("xy after getnextxy [%d, %d] \n", xy.x, xy.y);
		fillit(map, piece->next, xy, mapsize);
	}
	return (0);
	// if piece cannot be placed, piece at that spot is not part of the solution
	// go back to the last piece that was placed, and move that piece to the next spot
/*
	else
	{
		printf("skipxy and trying new xy...\n");
		xy = getnextxy(map, piece->content, mapsize);
		placexy(map, piece->content, piece->alpha, xy);
//		fillit(map, piece->next, xy, mapsize);		


//		printf("xy before skipxy: [%d, %d] \n", xy.x, xy.y);

//		if (skipxy(xy, mapsize) == 1)
//		{
//			printf("new xy confirmed [%d, %d] \n", xy.x, xy.y);
//			fillit(map, piece, xy, mapsize);
//		}
//		else
//			printf("nope sad face");
	}

//	printf("make the map bigger?\n");
	return (0);
*/
}
