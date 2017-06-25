/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:14:19 by nmougino          #+#    #+#             */
/*   Updated: 2017/06/25 19:40:57 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t), int tar)
{
	t_dlist	*cur;
	t_dlist	*nxt;

	cur = *alst;
	while (cur)
	{
		nxt = tar == TO_END ? cur->next : cur->prev;
		del(cur->content, cur->content_size);
		free(cur);
		cur = nxt;
	}
	*alst = NULL;
}
