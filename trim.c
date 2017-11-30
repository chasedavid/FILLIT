/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:52:22 by aho               #+#    #+#             */
/*   Updated: 2017/11/28 14:07:12 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_strsub_free(char *str, int col, int n)
{
	char		*orig;
	char		*new;

	orig = str;
	new = ft_strsub(str, col, n);
	free(orig);
	return (new);
}

char			*trimrows(char *str)
{
	int			spaces;
	int			hashes;
	int			i;

	spaces = 0;
	hashes = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		spaces += (str[i] == '.') ? 1 : 0;
		if (spaces == 4 && hashes == 0)
		{
			str = ft_strsub_free(str, i + 2, ft_strlen(str) - 4);
			spaces = 0;
			i = -1;
		}
		if (str[i] == '#')
			spaces = 0;
		if (str[i] == '#')
			++hashes;
		if (hashes == 4)
			return (check_hash_num(str, i));
	}
	return (str);
}

char			*t_deletecol(char *str, int col, int n)
{
	int			i;
	int			j;
	int			len;
	char		*trim;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (!(trim = malloc(ft_strlen(str) - 1)))
		return (NULL);
	while (i < len)
	{
		if (((i + 1) % n) == col)
			i++;
		else
			trim[j++] = str[i++];
	}
	trim[j] = '\0';
	free(str);
	return (trim);
}

char			*trimcols(char *str)
{
	int			i;
	int			col;
	int			indicator;
	int			n;
	int			len;

	col = 0;
	i = 0;
	n = 5;
	while (i < (n - 1))
	{
		col = (i + 1);
		indicator = 0;
		len = (int)ft_strlen(str);
		while (i < len)
		{
			indicator += ((str[i] == '#') ? 1 : 0);
			i += n;
		}
		if (indicator == 0)
			str = t_deletecol(str, col, n--);
		i = ((indicator == 0) ? col - 1 : col);
	}
	return (str);
}

char			*tettrim(char *str)
{
	str = trimrows(str);
	str = trimcols(str);
	return (str);
}
