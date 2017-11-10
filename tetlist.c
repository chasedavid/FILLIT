/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 01:00:29 by aho               #+#    #+#             */
/*   Updated: 2017/11/09 20:55:06 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

tet			*ft_tetnew(void const *content, unsigned int content_size, int alpha, int lst_i)
{
	tet		*link;


	if (!(link = ft_memalloc(sizeof(tet))))
		return (NULL);
	link->content = ft_memalloc(content_size);
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	link->alpha = alpha;
	link->x = 0; 
	link->y = 0; 
	link->lst_i = lst_i;
	link->next = NULL;
	return (link);
}

void		ft_tetappend(tet **alst, tet *new)
{
	tet		*current;
	
	current = (*(alst));
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	current->next->next = NULL;
}
