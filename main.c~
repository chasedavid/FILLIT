#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include "libft.h" 
#define BUF_SIZE 21


int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	t_list *linked_list;
	linked_list = ft_memalloc(sizeof(t_list));

	if (argc != 2) 
		ft_putstr("Incorrect number of arguments \n");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_putstr("open() failed \n");
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr("chars read: ");
		ft_putnbr(ret);
		ft_putchar('\n');
		ft_putstr(buf);
		check_buf(buf);
		if (isvalidtetri(buf) == 1)
			ft_lstappend(&linked_list, ft_lstnew(buf,22)); 
		ft_putchar('\n');
	}
	ft_putstr("file opened: ");	
	ft_putnbr(fd);
	ft_putchar('\n');
	ft_printlist(&linked_list);


	if (close(fd) == -1)
	{
		ft_putstr("close() failed \n");
		return (1);
	}
	return (0);
}

