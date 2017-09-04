/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 19:51:38 by nmougino          #+#    #+#             */
/*   Updated: 2017/09/04 20:03:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Detruit le maillon tar de la list lst en utilisant la fonction del.
*/

void	ft_lstrem(t_list **lst, t_list *tar, void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *lst;
	while (cur && cur != tar)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return ;
	if (prev)
		prev->next = cur->next;
	else
		*lst = cur->next;
	del(cur->content, cur->content_size);
	free(cur);
}
