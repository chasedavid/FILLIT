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


t_coord getnextxy(char **map, char *piece, int mapsize)
{
	t_coord xy;
	int x; 
	int y;
	x = 0; 
	y = 0;

	xy.x = x;
	xy.y = y;
//	printf("getnextxy() // piece:\n%s \n", piece);
	printf("getnextxy() // maprowavails() - spaces in row: %d \n", maprowavails(map[x]));
	printf("getnextxy() // piecewidth: %d \n", piecewidth(piece));

//	printf("x: %d  y: %d \n", x, y);

	while (x < mapsize)
	{
		y = 0;
		while (y < mapsize && (maprowavails(map[x]) >= piecewidth(piece))) 
		{
			printf("x: %d  y: %d \n", x, y);
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


char **placexy(char **map, char *piece, int alpha, t_coord xy)
{
	int i;
	int x; 
	int y;
	int len;

	i = 0;
	x = xy.x; 
	y = xy.y;
	len = ft_strlen(piece);
	while (len > 0)
	{
//		printf("piece[%i]: %c \n", i, piece[i]);
		if (piece[i] == '#') 
		{
			map[x][y] = alpha;
			y++;
			i++;
		}
		if (piece[i] == '\n') 
		{
			x++;
			y = xy.y;
			i++;
		}
		if (piece[i] == '.')
		{
			y++;
			i++;
		}
//		printf("piece: %s\n" , piece);
//		printf("xy.x: %d\n" , xy.x);
//		printf("xy.y: %d\n" , xy.y);
		len--;
	}
	return (map);
}



int checkxy(char **map, char *piece, t_coord xy)
{
	printf("\n>>>>>>>>>>>>>>>>>>> checkxy() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("piece:\n%s\n", piece);
	int x; 
	int y; 
	int setcol;
	int i;
	int piecelen;
	int pieces;

	x = 0; 
	y = 0;
	i = 0; 
	piecelen = ft_strlen(piece);
	newline = 0;
	pieces = 0;

		if ((piece[0] == '.') && (y - 1 > 0)) 
		{
			y = y - 1;
			setcol = y;

//			if (i < piecelen)
//			{
				if (piece[i] == '.') 
				{
					i++;
					y++;
				}
				if (piece[i] == '#' && map[x][y] == '.')
				{
					i++; 
					y++;
					pieces++;
				}
				if (piece[i] == '\n')
				{
					i++;
					x++;
					y = setcol;
				}
				if (piece[i] == '\0' && pieces != 4) 
				{					
					pieces = 0;
				}
				if (piece[i] == '\0' && pieces == 4) 
				{
					return (1);
				}
		}
	}
	return (-1);
}
