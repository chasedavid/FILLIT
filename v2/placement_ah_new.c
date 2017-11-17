/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_ah_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 02:18:13 by aho               #+#    #+#             */
/*   Updated: 2017/11/16 19:28:33 by aho              ###   ########.fr       */
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

int maprowavails(char *row)
{
    int i;
    int spaces;

//  printf("--------- maprowsavail() ------- \n");
//  printf("maprowsavail() row: %s \n\n", row);

    i = 0;
    spaces = 0;
    while (row[i] != '\0')
    {
        if (row[i] == '.')
            spaces++;
        i++;
    }
    return (spaces);
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
        while (y < size && (maprowavails(map[x]) >= firstrowpieces(piece)))
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
    return (xy);
}



int placetet(char **map, tet *tetr, int size, coord xy) //tet is validly placed
{
	int nextxy; 
	nextxy = getnextxy(map, tetr, size, xy);
	if (validmove == 1) 
	{	
		map = placexy(map, tetr, nextxy);
		return (1); 
	}
	else 
		return (-1);
}


int validmove(char **map, tet *tetr, int size, coord xy)
{
	xy = getnextxy();
	if (check(xy) == 1) 
		return (1);
	else 
		return (-1); 
}
