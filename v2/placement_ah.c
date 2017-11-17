#include "libft.h"

int piecewidth(char *piece)
{
//	printf("pieceswidth() \n");
//	printf("piece:\n%s \n", piece);

	int y; 
	y = 0;
	while (piece[y] != '\n') 
		y++;
	return (y);
}

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

//	printf("--------- maprowsavail() ------- \n");
//	printf("maprowsavail() row: %s \n\n", row);

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


t_coord 	getnextxy(char **map, char *piece, int mapsize)
{
	t_coord	xy;
	int		x; 
	int		y;

	x = 0; 
	y = 0;
	xy.x = x;
	xy.y = y;
//	printf("getnextxy() // piece:\n%s \n", piece);
//	printf("getnextxy() // maprowavails - spaces in row: %d \n", maprowavails(map[x]));
//	printf("getnextxy() // firstrowpieces: %d \n", firstrowpieces(piece));
//	printf("x: %d  y: %d \n", x, y);
	while (x < mapsize)
	{
		y = 0;
		while (y < mapsize && (maprowavails(map[x]) >= firstrowpieces(piece))) 
		{
//			printf("x: %d  y: %d \n", x, y);
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

int 		skipxy(t_coord xy, int mapsize)
{
	printf("-- skipxy xy.x : %d  \n", xy.x);
	printf("-- skipxy xy.y : %d  \n", xy.y);
	printf("-- skipxy mapsize : %d  \n", mapsize);
	if (xy.y + 1 < mapsize)
	{
		xy.y++;
		printf("go to next col - new xy [%d, %d] \n", xy.x, xy.y);
		return (1);
	}
	else if (xy.x + 1 < mapsize)
	{
		xy.y = 0;
		xy.x++;
		printf("go to next row - new xy [%d, %d] \n", xy.x, xy.y);
		return (1);
	}
	else
		return (-1);
}


 
int checkxy(char **map, char *piece, t_coord xy)
{
//	printf("\n>>>>>>>>>>>>>>>>>>> checkxy() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
//	printf("piece:\n%s\n", piece);
	int x; 
	int y; 
	int setcol;
	int i;
	int pieces;

	x = xy.x; 
	y = xy.y;
	i = 0; 
	pieces = 0;
	setcol = y;

	while (piece[i] != '\0')
	{
		//printf(">> inside checkxy - piece[%i]: %c // y: %i \n", i, piece[i], y);
//		if (piece[i] == '#' && i == 0)
//			setcol = y; 
		//for offset piece
		if ((piece[i] == '.') && i == 0 && (y - 1 > 0)) 
		{
//			printf(">> if loop 1:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			y = y - 1;
			setcol = y;
			y++;
		}
		if (piece[i] == '.' && i > 0) 
		{
//			printf(">> if loop 2:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			y++;
		}
		if (piece[i] == '#' && map[x][y] == '.')
		{
//			printf(">> if loop 3:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			y++;
			pieces++;
		}
		if (piece[i] == '\n')
		{
//			printf(">> if loop 4:  piece[%i]: %c // y: %i \n", i, piece[i], y);
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






char **placexy_offset(char **map, char *piece, int alpha, t_coord xy)
{
//	printf("\n>>>>>>>>>>>>>>>>>>> placexy_offset() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	int x; 
	int y; 
	int setcol;
	int i;

	x = xy.x; 
	y = xy.y;
	i = 0; 
	setcol = y;
	while (piece[i] != '\0')
	{
		//printf(">> inside checkxy - piece[%i]: %c // y: %i \n", i, piece[i], y);
		if ((piece[i] == '.') && i == 0 && (y - 1 > 0)) 
		{
//			printf(">> if loop 1:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			y = y - 1;
			setcol = y;
			y++;
		}
		if (piece[i] == '.' && i > 0) 
		{
//			printf(">> if loop 2:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			y++;
		}
		if (piece[i] == '#' && map[x][y] == '.')
		{
//			printf(">> if loop 3:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			map[x][y] = alpha;
			y++;
		}
		if (piece[i] == '\n')
		{
//			printf(">> if loop 4:  piece[%i]: %c // y: %i \n", i, piece[i], y);
			x++;
			y = setcol;
		}
		if (piece[i+1] == '\0') 
			return (map);
		i++;
	}
	return (map);
}




char **placexy(char **map, char *piece, int alpha, t_coord xy)
{
    int i;
    int x;
    int y;
	int pieces;
	int offset;
	int setcol;

    i = 0;
    x = xy.x;
    y = xy.y;
	pieces = 0;
	offset = 0;
//	if (piece[0] != '#') 
//		return placexy_offset(map, piece, alpha, xy);

//	else 
//	{
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
            map[x][y] = alpha;
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
//	}
    return (map);
}
