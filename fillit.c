#include "libft.h" 
#include <stdio.h>

char **makemap(int n)
{

	char **map;
	int i;
	int j;
	
	i = 0;
	if (!(map = (char**)malloc((n + 1) * sizeof(char*)))); 
		return (NULL);
	map[n + 1] = 0;
	while (i < n)
	{
		map[i] = ft_memalloc(n + 1);
		j = 0; 
		while (j < i(n + 1))
			map[i][j++] = '.';
		map[i][j] == '\0';
		i++;
	}
	return (map); 
}


void fillit(t_list **alst)
{
	char **map;
	int mapsize;
	t_list *current; //this is the current piece

	mapsize = 2;
	map = makemap(mapsize);

	int i;
	i = 0;
	while (i < mapsize) 
	{
		printf("map[%i]: %s \n", i, map[i]);
		i++;
	}






//	ft_printlist(alst);
	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, map, checkpiece);


	//once all pieces have been placed, print grid to show solution


}
