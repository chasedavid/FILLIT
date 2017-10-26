#include "libft.h" 
#include <stdio.h>

void fillit(t_list **alst)
{
	char *grid;
	t_list *current; //this is the current piece

	grid = ft_memalloc(7); //mallocs space for 2x2 (6 chars + null terminator)
	grid = "..\n..\n"; //initialize grid

//	printf("%s", grid);

//	ft_printlist(alst);

	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, grid, checkpiece);


	//once all pieces have been placed, print grid to show solution


}
