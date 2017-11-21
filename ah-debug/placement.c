/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_ah_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:18:13 by aho               #+#    #+#             */
/*   Updated: 2017/11/21 00:07:34 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int firstrowpieces(char *piece)
{
    int i;
    int pieces;
    i = 0;
    pieces = 0;
    while (piece[i] != '\n')
    {
        if (piece[i] == '#')
            pieces++;
        i++;
    }
    return (pieces);
}

int maprowavails(char *row, int size, coord *xy)
{
    int i;

//  printf("--------- maprowsavail() ------- \n");
//	printf("maprowavail() row: %s \n\n", row);
    i = 0;
// while (row[i] != '\0')
    while (xy->y < size && row[i] == '.')
    {
		i++;
		xy->y++;
    }
//	printf("maprowavails: %d \n",i);
    return (i);
}


coord	*getnextxy(char **map, tet *tetr, int size, coord *xy)
{
	printf("-------- getnextxy() ------- \n");
	printf("xy->x: %d, xy->y: %d \n", xy->x, xy->y);
	while (xy->x < size) 
	{
		xy->y = 0;
		while (xy->y < size && validmove(map, tetr, size, xy))
//      while (xy->y < size && (maprowavails(map[x], size, xy) >= firstrowpieces(tetr->content)))
        {
//          printf("x: %d  y: %d \n", x, y);
            if (map[xy->x][xy->y] == '.' && validmove(map, tetr, size, xy) == 1)
            {
				printf(">> map[x][y] == '.' - before return - xy->x: %d, xy->y: %d \n", xy->x, xy->y);
				return (xy);
            }
			else
				xy->y++; 
        }
        xy->x++;
	}
	printf(" before return - xy->x: %d, xy->y: %d \n", xy->x, xy->y);
    return (xy);
}


coord	*skipxy(char **map, tet *tetr, int size, coord *xy)
{
	xy = getnextxy(map, tetr, size, xy);
	while (xy->x < size) 
	{

		printf("beginning of skipxy: xy->x: %d, xy->y: %d, size: %d \n", xy->x, xy->y, size);
//		printf("tetr:\n %s \n", tetr->content);
//		printf("maprowavails: %d, tetr strlen: %zu \n", maprowavails(map[xy->x], size, xy), ft_strlen(tetr->content));
//		if ((xy->y + 1) < size && (maprowavails(map[xy->x], size, xy) >= firstrowpieces(tetr->content)))
//		if (checkxy(map, tetr, size, xy) == 1)
//			return (xy);
		if (xy->y + 1 < size)
		{
			xy->y++;
			return (xy);
		}
		else
		{
			xy->x++;
			xy->y = 0;
			return (xy);
//			printf("else new -  xy->x: %d, xy->y: %d \n", xy->x, xy->y);
		}
//		printf("testing xy->x: %d \n", xy->x);
	}
	printf("inside skipxy return: xy->x: %d, xy->y: %d \n", xy->x, xy->y);
    return (xy);
}


int placetet(char **map, tet *tetr, int size, coord *xy) //tet is validly placed
{
//	coord nextxy; 
//	nextxy = getnextxy(map, tetr, size, xy);
	printf("inside placetet -- xy->x: %d, xy->y: %d \n", xy->x, xy->y);

	if (validmove(map, tetr, size, xy) == 1) 
	{	
		map = placexy(map, tetr, size, xy);
		printmap(map,size);
		return (1); 
	}
	else
	{		
		return (-1);
	}

}


int validmove(char **map, tet *tetr, int size, coord *xy)
{
	if (checkxy(map, tetr, size, xy) == 1) 
		return (1);
	else 
		return (-1); 
}



int checkxy(char **map, tet *tetr, int size, coord *xy)
{
	printf("\n>>>>>>>>>>>>>>>>>>> checkxy() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("piece:\n%s\n", tetr->content);
    printf("checkxy -- xy->x: %d , xy->x: %d \n", xy->x, xy->y);
    int x;
    int y;
    int setcol;
    int i;
    int pieces;
	char *piece;

    x = xy->x;
    y = xy->y;
    i = 0;
    pieces = 0;
    setcol = y;
	piece = tetr->content;

    while (piece[i] != '\0')
    {
        if (piece[i] == '.')
        {
			printf(">> piece[%i]: %c // x: %i y: %i \n", i, piece[i], x, y);
            y++;
        }
        if (piece[i] == '#' && map[x][y] == '.' && y < size && x < size)
        {
			printf(">> piece[%i]: %c // x: %i y: %i \n", i, piece[i], x, y);
            y++;
            pieces++;
        }
        if (piece[i] == '\n')
        {
            x++;
            y = setcol;
        }
        if (piece[i+1] == '\0' && pieces == 4)
		{
			printf("checkxy return -- xy->x: %d , xy->x: %d \n", xy->x, xy->y);
	        return (1);
		}
        i++;
    }
    return (-1);
}


char **placexy(char **map, tet *tetr, int size, coord *xy)
{
	printf("placexy -- xy->x: %d , xy->x: %d \n", xy->x, xy->y);
    int i;
    int pieces;
    int offset;
    int setcol;
	char *piece;

    i = 0;
    pieces = 0;
    offset = 0;
	piece = tetr->content;
	setcol = xy->y;
    while (piece[i] != '\0')
    {
//		printf("piece[%i]: %c \n", i, piece[i]);
        if (piece[i] == '.')
        {
            if (pieces == 0)
                offset++;
//			    if (offset > 0 && piece[i + 1] == '#')
//			setcol = xy->y + offset;
            xy->y++;
        }
        if (piece[i] == '#')
        {
            map[xy->x][xy->y] = tetr->alpha;
            pieces++;
            xy->y++;
        }
        if (piece[i] == '\n')
        {
            xy->y = setcol;
            xy->x++;
        }
//      printf("piece: %s\n" , piece);
        if (piece[i + 1] == '\0')
		{
			printf("inside placexy - xy->x: %d , xy->y: %d \n", xy->x, xy->y);
            return (map);
		}
        i++;
    }
//  }
	getnextxy(map, tetr, size, xy);

	printf("inside placexy - xy->x: %d , xy->y: %d \n", xy->x, xy->y);
    return (map);
}
