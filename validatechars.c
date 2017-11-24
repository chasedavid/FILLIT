/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatechars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:40:30 by aho               #+#    #+#             */
/*   Updated: 2017/11/23 20:55:02 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			validchars(char *buf)
{
	int i;
	int dots;
	int hashes;
	int newlines;

	i = 0;
	dots = 0;
	hashes = 0;
	newlines = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (-1);
	while (buf[i] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		if (dots > 12 || hashes > 4 || newlines > 4)
			return (-1);
		if (buf[i] == '.')
			dots++;
		if (buf[i] == '#')
			hashes++;
		if (buf[i] == '\n')
			newlines++;
		i++;
	}
	if (dots != 12 || hashes != 4 || newlines != 4)
		return (-1);
	return (1);
}
