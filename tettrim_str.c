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
	free(str);
	return (trim);
}

char	*ft_something(char *str, int col, int n)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	j = 0;
	//malloc space for new string
	if (!(trim = malloc(ft_strlen(str) - 4)))
		return (NULL);
//	printf("malloc trim:\n%s \n", trim);
	//iterate through and copy str to malloc
	while (i < (int)ft_strlen(str))
	{
		if (((i + 1) % n) == col)
			i++;
		else
    		trim[j++] = str[i++];
	} 
	trim[j] = '\0';

//	trim = trimrows(trim, col); 

	free(str);
	return (trim);
}

char *trimcols(char *str)
{
	int		i;
	int		col;
	int		indicator;
	int 	n;
	int		len;

	col = 0;
	i = 0;
	n = 5;
	while (i < (n - 1))
	{
		col = (i + 1);
		indicator = 0;
		len = (int)ft_strlen(str);
		while (i < len)
		{
			if (str[i] == '#')
				indicator++;
			i += n;
		}
		if (indicator == 0)
		{
			str = ft_something(str, col, n);
			n--;
			i = col - 1;
		}
		else
			i = col;
	}
	free(str);
	return (str);
}





char *tettrim_str(char *str)
{
	char *trim; 
//	trim = trimrows(str);
	printf("original ft_strlen(str):%zu \n", ft_strlen(str));
	trim = trimcols(str);


	printf("trimmed string:\n%s \n", trim);
	return (trim); 
}
