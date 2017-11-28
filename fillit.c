/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/27 18:14:22 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	fillit(t_map *map, t_tet *tet)
{
	while (!(place_on_map(map, tet)))
		++(map->size);
	printmap((map->grid), (map->size));
}
