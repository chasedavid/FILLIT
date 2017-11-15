/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalidpiece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:58:01 by aho               #+#    #+#             */
/*   Updated: 2017/11/14 19:58:06 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> 

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
				printf("ERROR: empty");
				return (-1);
			}
		}
		if (buf[i] == '#') 
		{	
			//printf("buf[%i]: hash detected \n", i);
			spaces = 4;
			hashes++;
			if (hashes == 1) 
			{
				//check for neighboring hash
				
			}
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
		i++;
	}

	ft_putstr("\n--- isvalidpiece result: buf contains valid piece --- \n");
//	ft_putstr(buf);
			
	return (1); 
}
