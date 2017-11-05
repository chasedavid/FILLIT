/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 00:49:17 by aho               #+#    #+#             */
/*   Updated: 2017/10/15 00:49:55 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!size)
		return (0);
	ptr = (void*)malloc(size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
