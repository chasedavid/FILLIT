/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/17 19:51:56 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUF_SIZE 20

int			readtetfile(char *argv, tet **list)
{
    int		fd;
    int		ret;
//	char	buf[BUF_SIZE]
    char	*buf;
    int		alpha;
	int		tet_i;

	//gerardo was here
	buf = ft_strnew(20);
	alpha = 65;
	tet_i = 0;
    if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("Error\n");
        return (-1);
    }
    while ((ret = read(fd, buf, BUF_SIZE)))
    {
//        buf[ret] = '\0';
		if (validchars(buf) == 1 && validhashes(buf) == 1 && alpha < 91)
            ft_tetappend(list, ft_tetnew(buf, (BUF_SIZE + 1), alpha++, tet_i++));
		else
		{
			printf("invalid piece detected - see buf below:\n%s \n", buf);
//			return (-1);
		}
		ret = read(fd, buf, 1);
    }
    if (close(fd) == -1)
    {
        ft_putstr("Error\n");
        return (-1);
    }
	return (tet_i);
}
