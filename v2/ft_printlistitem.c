/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlistitem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:38:11 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 00:51:36 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void ft_printlistitem(t_list *item)
{
	printf("\n--- print list item ---\n");
	printf("item->alpha: %c \n", item->alpha);
	printf("item->content:\n%s \n", item->content);
}
