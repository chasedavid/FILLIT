#include "libft.h" 
#include <stdio.h>

char **makemap(int n) // function3
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

int ft_lstsize(t_list *last) // function2
{
	int num;

	num = (last->alpha) - 64;	
	printf("lstsize: %d \n", num);
	return (num);
}

int		ft_sqrt(int n)
{
	int		i;

	i = 1;
	while (i)
	{
		if ((i * i) >= n)
			return (i);
		++i;
	}
	return (0);
}


void fillit(t_list **alst, int min_n, int i, int j) // function 1
{
	char **map;
	int mapsize;
	t_list *current; //this is the current piece

	t_list *last; 
	last = ft_lstlastitem(alst);
	ft_lstsize(last);

	mapsize = min_n; // technically sqrt(4 * lst_size)
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
