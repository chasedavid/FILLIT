/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:26:45 by aho               #+#    #+#             */
/*   Updated: 2017/11/15 12:36:22 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> 

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

int         hashneighborcheck(char *buf, int i)
{
    if (hashrightcheck(buf, i) == 1) 
		return (1);
	if (hashbelowcheck(buf, i) == 1)
		return (1);
	if (hashleftcheck(buf, i) == 1)
		return (1);
	return (-1);
}

int validatebuf(char *buf)
{
	int i;
	int spaces;
	int hashes;

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
        if (buf[i] == '#' && hashneighborcheck(buf, i) == 1)
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
		if (hashneighborcheck(buf, i) == -1)
            return (-1);
		i++;
	}
	return (1); 
}
