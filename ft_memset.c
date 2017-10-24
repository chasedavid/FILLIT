/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 14:16:24 by aho               #+#    #+#             */
/*   Updated: 2017/10/14 19:33:54 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char ch;

	str = b;
	ch = c;
	while (0 < len)
	{
		*str = ch;
		str++;
		len--;
	}
	return (b);
}
