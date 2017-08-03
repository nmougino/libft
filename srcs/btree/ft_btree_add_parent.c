/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:30:13 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/03 18:32:45 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cette fonction ajoute un noeud en temps que parent de la racine envoyee.
** Pour ne rien perdre il est important que le la racine envoyee soit la plus haute
** Dans le cas contraire, ca va faire de la merde
*/

void	ft_btree_add_parent(t_btree **r, t_btree *new, int side)
{
	if (side == LEFT)
		new->left = *r;
	else
		new->right = *r;
	*r = new;
}
