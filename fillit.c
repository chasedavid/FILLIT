/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/20 17:27:09 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void	fillit(char **map, t_tet *tet, int size) 
{
	while(!(place_on_map(map, tet, size)))
		++size;
	printmap(map, size);
}
