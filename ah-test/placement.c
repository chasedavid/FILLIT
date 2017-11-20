/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_ah_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:18:13 by aho               #+#    #+#             */
/*   Updated: 2017/11/18 02:28:25 by aho              ###   ########.fr       */
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

int maprowavails(char *row, int size, coord xy)
{
    int i;

    i = 0;
    while (xy.y < size && row[i] == '.')
    {
		i++;
		xy.y++;
    }
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
		if (checkxy(map, tetr, size, xy) == 1)
			return (xy);
		else if (xy.y + 1 < size) 
			xy.y++; 
		else
		{
			xy.x++;
			xy.y = 0;
		}
	}
    return (xy);
}


int placetet(char **map, tet *tetr, int size, coord xy) //tet is validly placed
{
	coord nextxy; 
	nextxy = getnextxy(map, tetr, size, xy);
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
    while (piece[i] != '\0')
    {
        //for offset piece
        if ((piece[i] == '.') && i == 0 && (y - 1 > 0))
        {
            y = y - 1;
            setcol = y;
            y++;
        }
        if (piece[i] == '.' && i > 0)
            y++;
        if (piece[i] == '#' && map[x][y] == '.' && y < size)
        {
            y++;
            pieces++;
        }
        if (piece[i] == '\n')
        {
            x++;
            y = setcol;
        }
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
    setcol = y;
    while (piece[i] != '\0')
    {
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
        if (piece[i + 1] == '\0')
            return (map);
        i++;
    }
    return (map);
}
