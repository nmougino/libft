/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:20:32 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/20 17:27:48 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(void *data)
{
	t_btree	*ans;

	if (!(ans = malloc(sizeof(t_btree))))
		return (NULL);
	ans->data = data;
	ans->left = NULL;
	ans->right = NULL;
	return (ans);
}
