/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 20:19:34 by aho               #+#    #+#             */
/*   Updated: 2017/10/16 01:31:32 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	int		arr_len;
	int		str_len;
	int		i;
	int		a;

	a = -1;
	if (!s)
		return (0);
	arr_len = ft_wordcount(s, c);
	str_arr = (char**)malloc((arr_len + 1) * sizeof(char*));
	if (str_arr == 0)
		return (0);
	str_arr[arr_len] = 0;
	while (++a < arr_len)
	{
		while (*s == c)
			s++;
		str_len = ft_wordlen(s, c);
		str_arr[a] = ft_memalloc(str_len + 1);
		i = 0;
		while (i < str_len)
			str_arr[a][i++] = *(char*)s++;
	}
	return (str_arr);
}
