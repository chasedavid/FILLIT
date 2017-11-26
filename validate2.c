/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:41:43 by aho               #+#    #+#             */
/*   Updated: 2017/11/25 22:42:00 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
		while (hashes == 0 && buf[i] != '#')
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
	return ((hashes != 4 || counter != 3) ? -1 : 1);
}
