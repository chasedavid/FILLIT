#include "libft.h"
#include <stdio.h> 

char *trimrows(char *str)
{
	int spaces;
	int hashes;
	int len;
	int i;

	spaces = 0;
	hashes = 0;
	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			spaces++;
		if (spaces == 4 && hashes == 0) 
		{
			len = len - 4;
			str = ft_strsub(str, i + 2, len);
			spaces = 0;
			i = -1;
		}
		if (str[i] == '#') 
		{
			spaces = 0;
			hashes++;
		}
		if (hashes == 4) 
		{
			while (str[i] != '\n') 
				i++;
			str = ft_strsub(str, 0, i + 1);
			return (str);
		}
		i++;
	}
	return (str);
}

char	*t_deletecol(char *str, int col, int n)
{
	int		i;
	int		j;
	int 	len;
	char	*trim;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	//malloc space for new string
	if (!(trim = malloc(ft_strlen(str) - 4)))
		return (NULL);
	//iterate through and copy str to malloc
	while (i < len)
	{
		if (((i + 1) % n) == col)
			i++;
		else
    		trim[j++] = str[i++];
	} 
	trim[j] = '\0';
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
			str = t_deletecol(str, col, n);
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
	str = trimrows(str);
	str = trimcols(str);
	printf("trimmed string:\n%s \n", str);
	return (str); 
}