/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:19:54 by cfarnswo          #+#    #+#             */
/*   Updated: 2017/09/21 10:19:30 by cfarnswo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		return (c - 32);
	else
		return (c);
}
