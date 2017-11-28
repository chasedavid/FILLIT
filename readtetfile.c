/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/27 18:25:40 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int			readtetfile(char *argv, t_tet **list)
{
	int		fd;
	int		ret;
	char	*buf;
	int		alpha;
	int		i;

	alpha = 65;
	i = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 20)))
	{
		if (validchars(buf) == 1 && validhashes(buf) == 1 && alpha < 91)
			ft_tetappend(list, ft_tetnew(buf, 21, alpha++, i++));
		else
			return (-1);
		ft_strclr(buf);
		ret = read(fd, buf, 1);
	}
	if (ft_strlen(buf) == 1 || close(fd) == -1 || i == 0)
		return (-1);
	return (i);
}
