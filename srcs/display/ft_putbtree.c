/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbtree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:42:46 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/20 20:28:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le contenu d'un arbre binaire
** (considere data comme un char*)
*/

static void	ft_rec_putbtree(t_btree *r, int l, void (*ft_putfunc)(const char *))
{
	if (r)
	{
		ft_putfunc(r->data);
		if (r->left)
		{
			ft_printf("%*c|-left--: ", (l + 1) * 2, ' ');
			ft_rec_putbtree(r->left, l + 1, ft_putfunc);
		}
		if (r->right)
		{
			ft_printf("%*c|-right-: ", (l + 1) * 2, ' ');
			ft_rec_putbtree(r->right, l + 1, ft_putfunc);
		}
	}
}

void		ft_putbtree(t_btree *root, void (*ft_putfunc)(const char *))
{
	ft_rec_putbtree(root, 0, ft_putfunc);
}
