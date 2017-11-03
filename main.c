#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include "libft.h" 
#define BUF_SIZE 20

#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	t_list *linked_list;
	int alpha;
	int buf_marker;

	linked_list = ft_memalloc(sizeof(t_list));
	alpha = 65;
	buf_marker = 0;

	if (argc != 2) 
		ft_putstr("Incorrect number of arguments \n");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_putstr("open() failed \n");
		return (1);
	}

	
	while ((ret = read(fd, buf, BUF_SIZE)))	
//	while ((ret = read(fd, buf + buf_marker, BUF_SIZE + buf_marker)))
	{
		buf[ret] = '\0';
//		buf_marker += ret;



//		total = 0;
//		while (total < 21)
//		{
//			ret = read(fd, buf, BUF_SIZE + total);
			printf("\nret: %i \n", ret);
//			total = ret;
//			ft_putstr(buf);

//			ft_putstr("lalala");
//		ft_putstr("chars read: ");
//		ft_putnbr(ret);
//		ft_putchar('\n');
//		ft_putstr(buf);
//		check_buf(buf);

		if (isvalidpiece(buf) == 1)
		{
			ft_lstappend(&linked_list, ft_lstnew(buf, 21, alpha));
			alpha++; 
		}
		ret = read(fd, buf, 1);
//		ft_putchar('\n');


//		}
	}




//	ft_putstr(buf);

	ft_putstr("file opened: ");	
	ft_putnbr(fd);
	ft_putchar('\n');

	fillit(&linked_list);

//	ft_printlist(&linked_list);

	if (close(fd) == -1)
	{
		ft_putstr("close() failed \n");
		return (1);
	}
	return (0);
}

