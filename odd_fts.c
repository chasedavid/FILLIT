/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:03:14 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/11/22 10:58:46 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 int	ft_lstsize(t_list *last)
 {
	int		num;

	num = (last->alpha) - 64;
	return (num);
 }
 */

int		ft_width(char *s)
{
	int		i;

	i = -1;
	while(*s++ != '\n')
		++i;
	return (i);
}

int		ft_height(char *s)
{
	int		i;

	i = -1;
	while(*s)
		if (*s++ == '\n')
			++i;
	return (i);
}

int		ft_sqrt(int n)
{
	int		i;

	i = 1;
	while (i)
	{
		if ((i * i) >= n)
			return (i);
		++i;
	}
	return (0);
}
