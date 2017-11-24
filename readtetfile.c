/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/23 21:09:58 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 20

int			readtetfile(char *argv, t_tet **list)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	int		alpha;
	int		i;

	alpha = 65;
	i = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (validchars(buf) == 1 && validhashes(buf) == 1 && alpha < 91)
			ft_tetappend(list, ft_tetnew(buf, (BUF_SIZE + 1), alpha++, i++));
		else
			return (-1);
		ret = read(fd, buf, 1);
	}
	if (close(fd) == -1)
		return (-1);
	return (i);
}
