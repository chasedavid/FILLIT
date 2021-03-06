/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:53:15 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/14 11:40:44 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		s++;
		if (*s == '\0' && c != '\0')
			return (NULL);
	}
	return ((char*)s);
}
