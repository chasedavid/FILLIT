#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include "libft.h" 
#include "fillit.h"
#define BUF_SIZE 20

#include <stdio.h>

int 		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	t_list	*linked_list;
	int 	alpha;
	int 	lst_i; 

	lst_i = 0;
	linked_list = ft_memalloc(sizeof(t_list));
	alpha = 65;
	if (argc != 2) 
		ft_putstr("Incorrect number of arguments \n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_putstr("open() failed \n");
		return (1);
	}

	while ((ret = read(fd, buf, BUF_SIZE)))		
//	while ((ret = read(fd, buf, BUF_SIZE)) > 21)		
//	while ((ret = read(fd, buf + bufdone, BUF_SIZE - bufdone)) > 21)	
	{
		buf[ret] = '\0';
//		check_buf(buf);
		if (isvalidpiece(buf) == 1)
		{
			ft_lstappend(&linked_list, ft_lstnew(buf, 21, alpha, 0, 0, lst_i));
			alpha++;
			lst_i++;
		}
		ret = read(fd, buf, 1);
	}

//	while ((ret = read(fd, buf, BUF_SIZE)) > 20) 
//	{
//		buf[ret] = '\n';
//		buf[ret + 1] = '\0';
//		if (isvalidpiece(buf) == 1)
//		{
//			ft_lstappend(&linked_list, ft_lstnew(buf, 21, alpha));
//			alpha++; 
//		}
//	}

	ft_putstr("file opened: ");	
	ft_putnbr(fd);
	ft_putchar('\n');

//	fillit(&linked_list);
//	ft_printlist(&linked_list);

	if (close(fd) == -1)
	{
		ft_putstr("close() failed \n");
		return (1);
	}
	
// fillit
	fillit(&linked_list, ft_sqrt(4 * ++lst_i));

	return (0);
}

