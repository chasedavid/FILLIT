/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 01:00:29 by aho               #+#    #+#             */
/*   Updated: 2017/11/23 21:19:53 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

t_tet			*ft_tetnew(void *content, int tetsize, int alpha, int i)
{
	t_tet		*link;

	if (!(link = ft_memalloc(sizeof(t_tet))))
		return (NULL);
	link->content = ft_memalloc(tetsize);
	ft_memcpy(link->content, content, tetsize);
	link->content_size = tetsize;
	link->alpha = alpha;
	link->x = 0;
	link->y = 0;
	link->lst_i = i;
	link->next = NULL;
	return (link);
}

void			ft_tetappend(t_tet **alst, t_tet *new)
{
	t_tet		*current;

	current = (*(alst));
	if (current->content == NULL)
		*alst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		current->next->next = NULL;
	}
}

void			ft_printtetlist(t_tet **alst)
{
	t_tet		*current;
	int			i;

	current = (*(alst));
	i = 0;
	while (current != NULL)
	{
		printf("-----------------\n");
		printf("Linked List: %d\n", i);
		printf("-----------------\n");
		printf("current->content:\n%s\n", current->content);
		printf("current->alpha: %c \n", current->alpha);
		if (current->next == NULL)
			printf("current->next is NULL\n");
		else
			printf("current->next->content:\n%s \n", current->next->content);
		current = current->next;
		i++;
	}
}

void			*ft_lstlastitem(t_tet **alst)
{
	t_tet		*current;
	t_tet		*last;

	current = (*(alst));
	while (current->next != NULL)
		current = current->next;
	last = current;
	return (last);
}

void			trimpieces(t_tet *list)
{
	t_tet		*current;

	current = list;
	while (current != NULL)
	{
		if (current->content != NULL)
			current->content = tettrim(current->content);
		current->x = ft_width(current->content);
		current->y = ft_height(current->content);
		current = current->next;
	}
}
