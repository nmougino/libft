/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:02:29 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/22 18:18:00 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreemap(t_btree **root, void (*fun)(t_btree **t))
{
	if (*root)
	{
		fun(root);
		ft_btreemap(&((*root)->left), fun);
		ft_btreemap(&((*root)->right), fun);
	}
}
