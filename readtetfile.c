/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtetfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:14:44 by aho               #+#    #+#             */
/*   Updated: 2017/11/28 14:21:53 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	ft_strclr(buf);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (validchars(buf) == 1 && validhashes(buf) == 1 && alpha < 91)
			ft_tetappend(list, ft_tetnew(buf, (BUF_SIZE + 1), alpha++, i++));
		else
			return (-1);
		ft_strclr(buf);
		ret = read(fd, buf, 1);
	}
	if (ft_strlen(buf) == 1 || close(fd) == -1 || i == 0)
		return (-1);
	return (i);
}
