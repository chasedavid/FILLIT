/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:28:48 by aho               #+#    #+#             */
/*   Updated: 2017/10/26 02:03:26 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstiter(t_list *lst, char *str, void (*f)(t_list *elem, char *str, int c))
{
	t_list	*current;
	char *grid; 

	grid = str;

	current = lst;
	while (current)
	{
		f(current, grid, current->alpha);
		current = current->next;
	}
}
