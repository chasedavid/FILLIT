#include "libft.h" 
#include <stdio.h>
//this function checks if the data in link passed in can fit into the grid


void checkpiece(t_list *link, char **map, int alpha)
{
	char *piece;
	printf("------------- checkpiece() function -------------\n");
	printf("alpha: %c \n", alpha);
	printf("map[0]: %s \n", map[0]);
	printf("map[1]: %s \n", map[1]);
	printf("tetrimino piece:\n%s \n", link->content);


	if (link->content != 0)
	{
		//
		printf("------------- tettrim() function -------------\n");
		piece = tettrim_str(link->content);
//		map = trypiece(map, piece);


	//change available spaces in grid to match char
	//if there's a match, place link into solution list

	//if no match, pop first link to end of list and try all pieces again

	//if no solutions found, expand the grid and try all possible combos again (realloc space for new grid size)

	//if solution works, move onto the next piece



	}

}

