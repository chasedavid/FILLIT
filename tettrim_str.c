#include "libft.h"
#include <stdio.h> 

char *trimrows(char *str)
{
	char *trim;
	int spaces;
	int hashes;
	int len;
	int i;

	trim = str;
	spaces = 0;
	hashes = 0;
	len = ft_strlen(str);
	i = 0;
	while (trim[i] != '\0')
	{
		if (trim[i] == '.')
			spaces++;
		if (spaces == 4 && hashes == 0) 
		{
			len = len - 4;
			trim = ft_strsub(trim, i + 2, len);
			spaces = 0;
			i = -1;
		}
		if (trim[i] == '#') 
		{
			spaces = 0;
			hashes++;
		}
		if (hashes == 4) 
		{
			while (trim[i] != '\n') 
				i++;
			trim = ft_strsub(trim, 0, i + 1);
			return (trim);
		}
		i++;
	}
	return (trim);
}

/*
char *trimcols(char *str)
{




}
*/





char *tettrim_str(char *str)
{
	char *trim; 
	trim = trimrows(str);
//	trim = trimcols(trim);

	printf("trimrows():\n%s \n", trim);
	return (trim); 
}
