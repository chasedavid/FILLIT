/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastitem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:20:38 by aho               #+#    #+#             */
/*   Updated: 2017/11/04 19:20:41 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_lstlastitem(t_list **alst)
{
	t_list *current;
	t_list *last;
	current = (*(alst));
	while (current->next != NULL) 
		current = current->next; 
	last = current;
	return (last);
}
