/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:14:58 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/28 13:57:54 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(t_map *map, t_tet *tet)
{
	while (!(place_on_map(map, tet)))
		++(map->size);
	printmap((map->grid), (map->size));
}
