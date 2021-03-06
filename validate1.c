/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:37:17 by aho               #+#    #+#             */
/*   Updated: 2017/11/28 14:07:51 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			checkchars(char c)
{
	if (c != '.' && c != '#' && c != '\n')
		return (-1);
	return (1);
}

int			validchars(char *buf)
{
	int i;
	int dots;
	int hashes;
	int newlines;

	i = -1;
	dots = 0;
	hashes = 0;
	newlines = 0;
	if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n' || buf[19] != '\n')
		return (-1);
	while (buf[++i] != '\0')
	{
		if (checkchars(buf[i]) == -1 || dots > 12 || hashes > 4 || newlines > 4)
			return (-1);
		if (buf[i] == '.')
			dots++;
		if (buf[i] == '#')
			hashes++;
		if (buf[i] == '\n')
			newlines++;
	}
	if (dots != 12 || hashes != 4 || newlines != 4)
		return (-1);
	return (1);
}
