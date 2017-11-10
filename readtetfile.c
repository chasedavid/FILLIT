/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 18:44:12 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 20

int			readtetfile(char *argv, tet **list)
{
    int		fd;
    int		ret;
    char	buf[BUF_SIZE];
    int		alpha;
	int		tet_i;

	alpha = 65;
	tet_i = 0;
    if ((fd = open(argv, O_RDONLY)) < 0);
	{
		ft_putstr("Error\n");
        return (-1);
    }
    while ((ret = read(fd, buf, BUF_SIZE)))
    {
        buf[ret] = '\0';
        if (isvalidpiece(buf) == 1)
            ft_lstappend(list, ft_lstnew(buf, (BUF_SIZE + 1), alpha++, tet_i++));
        ret = read(fd, buf, 1);
    }
    if (close(fd) == -1)
    {
        ft_putstr("Error\n");
        return (-1);
    }
	return (++tet_i - 64);
}
