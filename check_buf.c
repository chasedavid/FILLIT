#include "libft.h"


int check_buf(char *buf)
{
	int i;
	i = 0;
	
	while (buf[i] != '\0')
	{
		ft_putstr("buf: ");
		ft_putchar(buf[i]);
		ft_putstr("\n");
		i++; 
	}

	if (checkbufchar(buf) == 1)
		ft_putstr("passes char check: all chars are valid \n");
//	ft_checkbufrow(buf); 
//	ft_checkbufcol(buf);

	ft_putstr("\n-end of check_buf function-\n");
	return (-1);
}
