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
	    //returns the column number if all rows checked have '.'
	  	if (array[i][j] == '.') 
		{
			counter++;
			if (counter == 4)
				return (j);
			i++;
		}
		// if not '.', then go to next column and reset the row & counter
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
	free(str);
	return (trim);
}


char **tettrimcol(char **array, int index)
{
	int i; 

	i = 0; 
	while (i < 4) 
	{
	  //store new trimmed row into the array
	  	array[i] = strtrimi(array[i], index);
		i++;
	}
	return (array);
}

/*
int checktetrow(char **array)
{
	  int i;
	  int j;
	  int hashinrow;
	  int counter;

	  i = 0;
	  j = 0;
	  hashinrow = 0;

	  while (i < 4)
	  {
	    while (array[i][j] = '.')
	      {
		j++;
		if (j == 4)
		  return (i);
	      }
	    if (array[i][j] != '.')
	      {
		hashinrow++;
		i++;
		j = 0;
	      }
	    if (j == 4 && hashinrow == 0)
	      {
		trimarray;
		gotonextrow;
	      }
	    if (j == 4 && hashinrow > 0)
	        return (array);
	

	    
	    if (i == 4)
	      return (-1);
	  }
}


char **tettrimrow(char **array, int row_index)
{
  int i;
  i = 0; 
  while (i < 3)
    {
      array[i]
    }






  
  //check if row contains all '.'
  //if row is before any hashes, move remaining rows up one row
  //check row again and repeat
  //if hash is found go to next row
  //if any more empty rows found, return 
  
  //if yes, mark that row to be deleted
  //delete that row
  //return new 2d array with trimmed row

  //either trimming above or below shape
  // if below, then return array is is
  // if above, then copy rows up 
  


}
*/

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

//	tettrimrows(tet2d);
	
	//trimcol stores the column number to be trimmed
	trimcol = checktetcol(tet2d);
	//while trimcol contains a number > 0
	while (trimcol >= 0)
	{
		tettrimcol(tet2d, trimcol);
		//free here?
		trimcol = checktetcol(tet2d);
	}
	

	i = 0; 
	while (i < 4)
	{
		printf("after trim - tet2d[%i]: %s \n", i, tet2d[i]);
		i++;
	}

}
