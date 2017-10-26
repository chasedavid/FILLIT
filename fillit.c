#include "libft.h" 

void fillit(t_list **alst)
{
	//counter for confirmed pieces? 
	char *grid;
	t_list *current; //this is the current piece

	grid = ft_memalloc(7); //mallocs space for 2x2 (6 chars + null terminator)
	current = *alst;

	// to be done: need to initialize grid with . 

	// 0. iterate through linked list to test each piece
	while (current->next != NULL)
	{
	// 1. placepiece() - check if piece fits into grid
		checkpiece(current, grid, counter);
		current = current->next;
	}

	//once all pieces have been placed, print grid to show solution


}
