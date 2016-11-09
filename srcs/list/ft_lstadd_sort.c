/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 13:04:42 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/21 13:59:38 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Ajoute un element dans une liste de maniere triee selon
** le resultat de la fonction sfun pasee en parametre qui
** compare les maillons.
*/

void	ft_lstadd_sort(t_list **alst, t_list *new, int (*sfun)(void *, void *))
{
	t_list	*tmp;

	if (alst && new)
	{
		if (!*alst)
			*alst = new;
		else if (sfun(new, *alst))
		{
			new->next = *alst;
			*alst = new;
		}
		else
		{
			tmp = *alst;
			while (tmp->next && sfun(tmp->next, new))
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}
