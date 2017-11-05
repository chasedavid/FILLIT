#include "libft.h"

char **trypiece(char **map, char *piece)
{
	printf("\n>>>>>>>>>>>>>>>>>>> trypiece() function <<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("piece:\n%s\n", piece);
	int x; 
	int y; 
	int setcol; 

	x = 0; 
	y = 0;
	setcol = x;

	//while maplen > 0
	
	if (map[x][y] == '.')
	{
		printf("true");
	}

	//go to first coordinate with '.'
	//mark the column 
	//match the width of the first row of the piece 
	//move on to the next row 



	return (map);
}
