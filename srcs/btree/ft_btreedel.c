/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:18:48 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/03 17:36:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcoure l'arbre, en applicant la fonction de destruction a chaque contenu
** de chaque noeud, puis detruit ce noeud.
*/

void	ft_btreedel(t_btree **r, void (*fun)(void *))
{
	if (!*r)
		return ;
	fun((*r)->data);
	if ((*r)->left)
		ft_btreedel(&((*r)->left), fun);
	if ((*r)->right)
		ft_btreedel(&((*r)->right), fun);
	ft_memdel((void**)r);
}
