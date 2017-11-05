#include "libft.h" 
#include <stdio.h>

char **makemap(int n)
{

	char **map;
	int i;
	int j;
	
	i = 0;
	if (!(map = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	map[n + 1] = 0;
	while (i < n)
	{
		map[i] = ft_memalloc(n + 1);
		j = 0;
		while (j < n)
			map[i][j++] = '.';
		map[i][j] = '\0';
		i++;
	}
	return (map); 
}



void fillit(t_list **alst)
{
	char **map;
	int mapsize;
	t_list *current; //this is the current piece
	t_coord xy;

	mapsize = 3; // technically sqrt(4 * lst_size)
	map = makemap(mapsize);

	char *hardcodestring = "AB...\nAB...\nA....\nA....\n";
	char **hardcodemap = ft_strsplit(hardcodestring, '\n');
//	printf("\n >>>> arr2dlenrow: %d \n", arr2dlenrow(map));
//	printf("\n >>>> arr2dlencol: %d \n", arr2dlencol(map));	

/*
	int i;
	i = 0;
	while (i < mapsize) 
	{
		printf("map[%i]: %s \n", i, map[i]);
		i++;
	}

//	if (map[1][3] == '\0') 
//		printf("map[1][3]: %c equals null terminator\n", map[1][3]);
*/
	current = *alst;
//	xy = getnextxy(map, tettrim_str(current->next->content), mapsize);

	xy = getnextxy(hardcodemap, tettrim_str(current->next->content), 5);
	printf("fillit() ----- xy->x: %d \n", xy.x);
	printf("fillit() ----- xy->y: %d \n", xy.y);



//	ft_printlist(alst);
	current = *alst;

	// 0. iterate through linked list to test each piece
	ft_lstiter(*alst, map, checkpiece);


	//once all pieces have been placed, print grid to show solution


}
