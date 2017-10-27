#include "libft.h"
#include <stdio.h>

int checktetcol(char **array)
{
	int i; 
	int j;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	while (i < 4)
	{
		if (array[i][j] == '.') 
		{
			counter++;
			if (counter == 4)
				return (j);
			i++;
		}
		else if (array[i][j] != '.') 
		{
			j++;
			i = 0;
			counter = 0;
		}
		if (j > 4) 
			return(-1);
	}
	return (-1);
}

char *strtrimi(char *str, int index)
{
	int i;
	int j;
	char *trim; 
	trim = ft_memalloc(ft_strlen(str));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (i == index) 
			j++;
		trim[i] = str[j];
		i++; 
		j++; 
	}
	return (trim);
}


char **tettrimcol(char **array, int index)
{
	int i; 

	i = 0; 
	while (i < 4) 
	{
		array[i] = strtrimi(array[i], index);
		i++;
	}
	return (array);
}


void tettrim(char *str)
{
	char **tet2d;
	int i; 
	int trimcol;

	tet2d = ft_strsplit(str, '\n');

	i = 0; 
	while (i < 4)
	{
		printf("tet2d[%i]: %s \n", i, tet2d[i]);
		i++;
	}


	trimcol = checktetcol(tet2d);
	while (trimcol >= 0)
	{
		tettrimcol(tet2d, trimcol);
		trimcol = checktetcol(tet2d);
	}
	

	i = 0; 
	while (i < 4)
	{
		printf("after trim - tet2d[%i]: %s \n", i, tet2d[i]);
		i++;
	}

}
