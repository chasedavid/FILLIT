#include "libft.h" 

//this function checks if the data in link passed in can fit into the grid

void checkpiece(t_list *link, char *grid, char c)
{
	char counter[1];
	char *piece;

	piece = trimpiece(link);
	counter = 'A'; 

	//get information from link being passed in

	//change available spaces in grid to match char
	//if there's a match, place link into solution list

	//if no match, pop first link to end of list and try all pieces again

	//if no solutions found, expand the grid and try all possible combos again (realloc space for new grid size)

	//if solution works, move onto the next piece





}
