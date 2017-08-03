/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:02:29 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/03 17:37:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parcoure l'arbre en appliquant la fonction a chaque noeud.
*/

void	ft_btreemap(t_btree **root, void (*fun)(t_btree **t))
{
	if (*root)
	{
		fun(root);
		ft_btreemap(&((*root)->left), fun);
		ft_btreemap(&((*root)->right), fun);
	}
}
