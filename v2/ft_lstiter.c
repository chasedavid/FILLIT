/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:28:48 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 17:51:55 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
    printf("\n----- entering lstiter.c -------\n");
	t_list	*current;
	current = lst;
	while (current)
	{
		f(current);
		printf("lstiter.c - current->content:\n%s\n", current->content);
		current = current->next;
	}
}
