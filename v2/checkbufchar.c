#include "libft.h"

int checkbufchar(char *buf) 
{
	int i;
	i = 0;
	while (buf[i] != '\0')
	{
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (-1);
		if ((i + 1) % 5 != 0) 
			if (buf[i] != '.' || buf[i] != '#') 
			return (-1); 
		i++;
	}
	return (1);
}
