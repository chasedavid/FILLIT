/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:28:48 by aho               #+#    #+#             */
/*   Updated: 2017/11/02 11:55:03 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstiter(t_list *lst, char **map, void (*f)(t_list *elem, char **map, int c))
{
	t_list	*current;
//	char **map; 

//	map = str;

	current = lst;
	while (current)
	{
		f(current, map, current->alpha);
		current = current->next;
	}
}
