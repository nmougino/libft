/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:48:42 by nmougino          #+#    #+#             */
/*   Updated: 2017/10/21 14:11:11 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_add(t_btree *new, t_btree *parent, int side)
{
	if (side == LEFT)
		parent->left = new;
	else
		parent->right = new;
	new->parent = parent;
}
