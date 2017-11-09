/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsizemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:56:17 by aho               #+#    #+#             */
/*   Updated: 2017/11/07 01:45:38 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int mapsizemin(t_list **list)
{
	t_list *last; 
	int min;
	last = ft_lstlastitem(list);
	min = 5;
//	min = ft_lstsize(last); 
//	printf("mapsizemin.c - number of items in list: %d \n", min);
//	min = ft_sqrt(min);
	return (min);
}
