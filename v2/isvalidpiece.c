/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalidpiece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:58:01 by aho               #+#    #+#             */
/*   Updated: 2017/11/15 02:15:08 by aho              ###   ########.fr       */
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



int isvalidpiece(char *buf)
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


/*
// TEST DEBUGGING VERSION WITH PRINT STATEMENTS
int isvalidpiece(char *buf)
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
			{
				printf("ERROR: empty \n");
				return (-1);
			}
		}
        if (buf[i] == '#' && hashneighborcheck(buf, i) == 1)
		{	
			//printf("buf[%i]: hash detected \n", i);
			spaces = 4;
			hashes++;
			if (hashes > 4)
			{
				printf("ERROR: not a valid piece - additional hash \n");
				return (-1);
			}
		}
		if (buf[i] != '#' && buf[i] != '\0' && hashes < 4)
		{
			//printf("buf[%i]: space detected \n", i);
			if (spaces == 0) 
			{
				//printf("buf[%i]: space detected \n", i);
				printf("ERROR: not a valid piece - too many spaces \n");
				return (-1);
			}
			spaces--;
		}
		if (hashneighborcheck(buf, i) == -1)
		{
			printf("ERROR: not a valid piece - fails neighbor check \n");	
            return (-1);
		}
		i++;
	}

	ft_putstr("\n--- isvalidpiece result: buf contains valid piece --- \n");
//	ft_putstr(buf);
			
	return (1); 
}
*/
