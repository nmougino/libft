/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbtreearr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:42:46 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/30 19:25:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche le contenu d'un arbre binaire
** (considere data comme un char**)
*/

static void	ft_rec_putbtreearr(t_btree *r, int l)
{
	char	*str;
	if (r)
	{
		if ((str = ft_arrglu(r->data, "| |", 3)))
		{
			ft_putstr("|");
			ft_putstr(str);
			ft_putendl("|");
			free(str);
		}
		if (r->left)
		{
			ft_printf("%*c|-left--: ", (l + 1) * 2, ' ');
			ft_rec_putbtreearr(r->left, l + 1);
		}
		if (r->right)
		{
			ft_printf("%*c|-right-: ", (l + 1) * 2, ' ');
			ft_rec_putbtreearr(r->right, l + 1);
		}
	}
}

void		ft_putbtreearr(t_btree *root)
{
	ft_rec_putbtreearr(root, 0);
}
