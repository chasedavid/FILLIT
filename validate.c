/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:26:45 by aho               #+#    #+#             */
/*   Updated: 2017/11/23 18:22:39 by cfarnswo         ###   ########.fr       */
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

int         hashneighborcheck(char *buf, int i, int hashes)
{
	if (hashes > 2)
		return (1);
	if (hashrightcheck(buf, i) == 1) 
		return (1);
	if (hashbelowcheck(buf, i) == 1)
		return (1);
	if (hashleftcheck(buf, i) == 1)
		return (1);
	return (-1);
}

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
		{
			printf("error return: invalid character detected \n");
			return (-1);
		}
		if (dots > 12 || hashes > 4 || newlines > 4) 
		{
			printf("error return: too many dots/hashes/newlines  \n");
			return (-1);
		}
		if (buf[i] == '.') 
			dots++;
		if (buf[i] == '#') 
			hashes++;
		if (buf[i] == '\n') 
			newlines++;
		i++;
	}
	if (dots != 12 || hashes != 4 || newlines != 4)
	{
		printf("error return: not enough dots/hashes/newlines");
		return (-1);
	}
	return (1); 
}
int			validhashes(char *buf)
{
	int		i;
	int		spaces;
	int		hashes;

	i = 0; 
	hashes = 0;
	//	printf("buf:\n%s \n", buf);
	while (buf[i] != '\0')
	{
		while (buf[i] != '#' && hashes == 0)
		{
			i++;
			if (buf[i] == '\0')
			{
				printf("error return: end of buf  \n");
				return (-1);
			}
		}
		if (buf[i] == '#' && hashneighborcheck(buf, i, hashes) == 1)
		{	
			spaces = 4;
			hashes++;
			if (hashes > 4)
			{
				printf("error return: hashes > 4 \n");
				return (-1);
			}
		}
		if (buf[i] != '#' && buf[i] != '\0' && hashes < 4)
		{
			if (spaces == 0)
			{
				printf("error return: spaces == 0 \n");
				return (-1);
			}
			spaces--;
		}
		//		printf("hashneighborcheck result: %d, i: %d \n", hashneighborcheck(buf, i), i);
		if (buf[i] == '#' && hashneighborcheck(buf, i, hashes) == -1)
		{
			printf("hashes: %d \n", hashes);
			printf("error return: does not pass hashneighborcheck at buf[%i]: %c \n", i, buf[i]);
			return (-1);
		}
		i++;
	}
	return (1); 
}
