/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:26:45 by aho               #+#    #+#             */
/*   Updated: 2017/11/25 21:44:08 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

/*
int			hashrightcheck(char *buf, int i)
{
	if (buf[i + 1] == '#')
		return (1);
	return (-1);
}

int			hashleftcheck(char *buf, int i)
{
	if (buf[i - 1] == '#')
		return (1);
	return (-1);
}

int			hashbelowcheck(char *buf, int i)
{
	if (buf[i + 5] == '#')
		return (1);
	return (-1);
}

int			hashneighborcheck(char *buf, int i, int hashes)
{
	if (hashes > 2)
		return (1);
	hashes = 0;
	if (hashrightcheck(buf, i) == 1)
		return (1);
	if (hashbelowcheck(buf, i) == 1)
		return (1);
	if (hashleftcheck(buf, i) == 1)
		return (1);
	return (-1);
}
*/
int			neighborhash(char *buf, int i)
{
	int counter;

	counter = 0;
	if (buf[i + 1] == '#' || buf[i + 5] == '#')
	{
		++counter;
		if (buf[i + 1] == '#' && buf[i + 5] == '#') 
			if (buf[i + 6] != '#')
				++counter; 
	}
	return (counter);
}

int			validhashes(char *buf)
{
	int		i;
	int		hashes;
	int		counter;

	i = 0;
	hashes = 0;
	counter = 0;
	while (buf[i] != '\0')
	{
		while (hashes == 0  && buf[i] == '#')
		{
			++i;
			if (buf[i] == '\0')
				return (-1);
		}
		if (buf[i] == '#')
		{
			hashes += (((hashes + 1) > 4) ? 0 : 1);
			counter += neighborhash(buf, i);
		}
		++i;
	}
	printf("%d:\n%d:\n", hashes, counter);
	return ((hashes != 4 || counter != 3) ? -1 : 1);
}
/*
int			validhashes(char *buf)
{
	int		i;
	int		spaces;
	int		hashes;

	i = 0;
	hashes = 0;
	while (buf[i] != '\0')
	{
		while (buf[i] != '#' && hashes == 0)
		{
			i++;
			if (buf[i] == '\0')
				return (-1);
		}
		if (buf[i] == '#' && hashneighborcheck(buf, i, hashes) == 1)
		{
			spaces = 4;
			hashes++;
			if (hashes > 4)
				return (-1);
		}
		if (buf[i] != '#' && buf[i] != '\0' && hashes < 4)
		{
			if (spaces == 0)
				return (-1);
			spaces--;
		}
		if (buf[i] == '#' && hashneighborcheck(buf, i, hashes) == -1)
			return (-1);
		i++;
	}
	return (1);
}*/
