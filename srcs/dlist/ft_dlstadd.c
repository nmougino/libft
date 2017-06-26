/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:04:42 by nmougino          #+#    #+#             */
/*   Updated: 2017/06/26 19:45:54 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute un element dans une liste doublement chainee.
*/

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (alst && new)
	{
		if (!(*alst))
			new->prev = NULL;
		else
		{
			new->prev = (*alst)->prev;
			if ((*alst)->prev)
				(*alst)->prev->next = new;
			(*alst)->prev = new;
		}
		new->next = *alst;
		*alst = new;
	}
}
