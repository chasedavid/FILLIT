/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 00:28:26 by aho               #+#    #+#             */
/*   Updated: 2017/10/23 22:31:57 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *current; 
	current = (*(alst));
	while (current->next != NULL)
		current = current->next;
	current->next = new; 
	current->next->next = NULL;
	current->next->prev = current;
}
