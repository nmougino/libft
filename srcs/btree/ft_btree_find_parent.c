/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find_parent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:02:20 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/03 18:07:44 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cette fonction retrouve le parent du second parametre en recherchant
** dans le premier.
*/

t_btree	*ft_btree_find_parent(t_btree *r, t_btree *tar)
{
	if (!r)
		return (NULL);
	if (r->left == tar || r->right == tar)
		return (r);
	if (r->left)
		return (ft_btree_find_parent(r->left, tar));
	if (r->right)
		return (ft_btree_find_parent(r->right, tar));
	return (NULL);
}
