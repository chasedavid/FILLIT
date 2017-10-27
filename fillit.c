#include "libft.h" 
#include <stdio.h>

char *makemap(int n)
{
	int maplen;
	int i; 
	char *map;
	
	i = 0;
	maplen = (n * n) + n + 1;
	map = ft_memalloc(maplen);
	map[maplen] = '\0';
	while (i < (maplen - 1))
	{
		if (((i + 1) % (n + 1)) == 0 ) 
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	return (map); 
}


void fillit(t_list **alst)
{
	char *map;
	int mapsize;
	t_list *current; //this is the current piece

	mapsize = 2;
	map = makemap(mapsize);

	printf("map:\n%s \n", map);

//	grid = ft_memalloc(7); //mallocs space for 2x2 (6 chars + null terminator)
//	grid = "..\n..\n"; //initialize grid

//	printf("%s", grid);

//	ft_printlist(alst);

	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, map, checkpiece);


	//once all pieces have been placed, print grid to show solution


}
