#include "libft.h" 

void fillit(t_list **alst)
{
	//counter for confirmed pieces? 
	char *grid;
	t_list *current; //this is the current piece
	char counter[1];


	grid = ft_memalloc(7); //mallocs space for 2x2 (6 chars + null terminator)
	current = *alst;
	//initialize grid with . 
	counter = 'A';

	// 0. iterate through linked list to test each piece
	while (current->next != NULL)
	{
		getpiece(current);
	// 1. lstpop() - "clone" or get information from the first link in linkedlist (get dimensions of piece)
		// function to move current node (instead of moving first link to the end)
	// 2. placepiece() - check if piece fits into grid
		if (placepiece(current, grid, counter) == 1)
			counter++;

	// 2. if yes, then place into grid and assign alpha char
	// 2. if no, recursion call to shift piece to the next possible place
	// 2. if no possible placement after rearranging pieces, then expand the grid and try again with recursion
		// realloc space (custom function? or use memalloc again)
	// 3. recursion call to place next piece
		current = current->next;
	}
}
