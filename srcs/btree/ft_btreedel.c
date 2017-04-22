/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:18:48 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/22 18:22:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreedel(t_btree *r, void (*fun)(void *))
{
	fun(r->data);
	if (r->left)
		ft_btreedel(r->left, fun);
	if (r->right)
		ft_btreedel(r->right, fun);
	ft_free(r);
}
