/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimpieces_direct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:36:14 by aho               #+#    #+#             */
/*   Updated: 2017/11/07 00:42:04 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void trimpieces(t_list *list)
{
	t_list *current;
	current = list;
    while (current != NULL)
    {
        if (current->content != NULL)
			current->content = tettrim_str(current->content);
		current = current->next;
    }
}
