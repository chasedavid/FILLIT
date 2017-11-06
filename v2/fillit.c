/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:15:22 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 01:06:46 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int fillit(char **map, t_list *piece, t_coord xy, int mapsize)
{
	xy = getnextxy(map, piece->content, mapsize);
	if (checkxy(map, piece->content, xy) == 1) 
		placexy(map, piece->content, piece->alpha, xy);
	else
		printf("nope sad face \n"); 



	return (0);
}
