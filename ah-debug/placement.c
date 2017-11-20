/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_ah_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:18:13 by aho               #+#    #+#             */
/*   Updated: 2017/11/18 02:10:16 by aho              ###   ########.fr       */
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

// probably some memory leak since print char *row is a really long string...
int maprowavails(char *row, int size, coord xy)
{
    int i;

//  printf("--------- maprowsavail() ------- \n");
//	printf("maprowavail() row: %s \n\n", row);
    i = 0;
// while (row[i] != '\0')
    while (xy.y < size && row[i] == '.')
    {
		i++;
		xy.y++;
    }
//	printf("maprowavails: %d \n",i);
    return (i);
}


coord	getnextxy(char **map, tet *tetr, int size, coord xy)
{
	int	x; 
	int y;

	x = 0; 
	y = 0;
	
	while (x < size) 
	{
		y = 0;
        while (y < size && (maprowavails(map[x], size, xy) >= firstrowpieces(tetr->content)))
        {
//          printf("x: %d  y: %d \n", x, y);
            if (map[x][y] == '.')
            {
                xy.x = x;
                xy.y = y;
                return (xy);
            }
            else if (map[x][y] != '.' && map[x][y] != 0)
            {
                y++;
            }

        }
        x++;
	}
	printf("xy.x: %d, xy.y: %d \n", xy.x, xy.y);
    return (xy);
}


coord	skipxy(char **map, tet *tetr, int size, coord xy)
{
	xy = getnextxy(map, tetr, size, xy);
	while (xy.x < size) 
	{
		printf("beginning of skipxy: xy.x: %d, xy.y: %d, size: %d \n", xy.x, xy.y, size);
//		printf("tetr:\n %s \n", tetr->content);
		printf("maprowavails: %d, tetr strlen: %zu \n", maprowavails(map[xy.x], size, xy), ft_strlen(tetr->content));
//		if ((xy.y + 1) < size && (maprowavails(map[xy.x], size, xy) >= firstrowpieces(tetr->content)))
		if (checkxy(map, tetr, size, xy) == 1)
			return (xy);
		else if (xy.y + 1 < size) 
			xy.y++; 
		else
		{
			xy.x++;
			xy.y = 0;
			printf("else new -  xy.x: %d, xy.y: %d \n", xy.x, xy.y);
		}
		printf("testing xy.x: %d \n", xy.x);
	}
	printf("skipxy: xy.x: %d, xy.y: %d \n", xy.x, xy.y);
    return (xy);
}


int placetet(char **map, tet *tetr, int size, coord xy) //tet is validly placed
{
	coord nextxy; 
	nextxy = getnextxy(map, tetr, size, xy);
	printf("nextxy.x: %d, nextxy.y: %d \n", nextxy.x, nextxy.y);

	if (validmove(map, tetr, size, nextxy) == 1) 
	{	
		map = placexy(map, tetr, nextxy);
		return (1); 
	}
	else 
		return (-1);
}


int validmove(char **map, tet *tetr, int size, coord xy)
{
	if (checkxy(map, tetr, size, xy) == 1) 
		return (1);
	else 
		return (-1); 
}



int checkxy(char **map, tet *tetr, int size, coord xy)
{
//  printf("\n>>>>>>>>>>>>>>>>>>> checkxy() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
//  printf("piece:\n%s\n", piece);
    int x;
    int y;
    int setcol;
    int i;
    int pieces;
	char *piece;

    x = xy.x;
    y = xy.y;
    i = 0;
    pieces = 0;
    setcol = y;
	piece = tetr->content;
	printf("piece:\n%s\n", piece);

    while (piece[i] != '\0')
    {
        //printf(">> inside checkxy - piece[%i]: %c // y: %i \n", i, piece[i], y);
//      if (piece[i] == '#' && i == 0)
//          setcol = y;

        //for offset piece
        if ((piece[i] == '.') && i == 0 && (y - 1 > 0))
        {
//          printf(">> if loop 1:  piece[%i]: %c // y: %i \n", i, piece[i], y);
            y = y - 1;
            setcol = y;
            y++;
        }
        if (piece[i] == '.' && i > 0)
        {
//          printf(">> if loop 2:  piece[%i]: %c // y: %i \n", i, piece[i], y);
            y++;
        }

//		printf("size: %d \n", size);
//		printf(">> if loop 3:  piece[%i]: %c // map[%i][%i] // - char: %c \n", i, piece[i], x, y, map[x][y]);
        if (piece[i] == '#' && map[x][y] == '.' && y < size)
        {
//			printf(">> if loop 3:  piece[%i]: %c // map[%i][%i] // - char: %c \n", i, piece[i], x, y, map[x][y]);
            y++;
            pieces++;
        }

//		else
//		{
//			printf("return -1: out of bounds \n");
//			return (-1);
//		}
        if (piece[i] == '\n')
        {
//          printf(">> if loop 4:  piece[%i]: %c // y: %i \n", i, piece[i], y);
            x++;
            y = setcol;
        }

//		if piece

        if (piece[i+1] == '\0' && pieces != 4)
            return (-1);
        if (piece[i+1] == '\0' && pieces == 4)
            return (1);
        i++;
    }
    return (-2);
}


char **placexy(char **map, tet *tetr, coord xy)
{
    int i;
    int x;
    int y;
    int pieces;
    int offset;
    int setcol;
	char *piece;

    i = 0;
    x = xy.x;
    y = xy.y;
    pieces = 0;
    offset = 0;
	piece = tetr->content;
//  if (piece[0] != '#')
//      return placexy_offset(map, piece, alpha, xy);

//  else
//  {
    setcol = y;
    while (piece[i] != '\0')
    {
//      printf("piece[%i]: %c \n", i, piece[i]);
        if (piece[i] == '.')
        {
            if (pieces == 0)
                offset++;
            if (offset > 0 && piece[i + 1] == '#')
                setcol = y - offset;
            y++;
        }
        if (piece[i] == '#')
        {
            map[x][y] = tetr->alpha;
            pieces++;
            y++;
        }
        if (piece[i] == '\n')
        {
            y = setcol;
            x++;
        }
//      printf("piece: %s\n" , piece);
//      printf("xy.x: %d\n" , xy.x);
//      printf("xy.y: %d\n" , xy.y);
        if (piece[i + 1] == '\0')
            return (map);
        i++;
    }
//  }
    return (map);
}
