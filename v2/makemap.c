/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aho <aho@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:36:30 by aho               #+#    #+#             */
/*   Updated: 2017/11/06 00:55:34 by aho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **makemap(int n)
{
    char **map;
    int i;
    int j;

    i = 0;
    if (!(map = (char**)malloc((n + 1) * sizeof(char*))))
        return (NULL);
    map[n + 1] = 0;
    while (i < n)
    {
        map[i] = ft_memalloc(n + 1);
        j = 0;
        while (j < n)
            map[i][j++] = '.';
        map[i][j] = '\0';
        i++;
    }
    return (map);
}
