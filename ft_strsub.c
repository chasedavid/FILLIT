/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 00:56:56 by aho               #+#    #+#             */
/*   Updated: 2017/10/15 01:07:21 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;
	char	*substr;

	i = 0;
	str = (char*)s;
	substr = ft_memalloc(len + 1);
	if (substr == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	while (len > 0)
	{
		substr[i] = str[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
