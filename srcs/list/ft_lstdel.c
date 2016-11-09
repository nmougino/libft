/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:14:19 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/21 14:49:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = nxt;
	}
	*alst = NULL;
}
