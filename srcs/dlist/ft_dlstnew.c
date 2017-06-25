/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 07:55:35 by nmougino          #+#    #+#             */
/*   Updated: 2017/06/25 21:04:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist *lst;

	if (!(lst = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = malloc(content_size);
		if (lst->content == NULL)
			return (NULL);
		ft_memcpy((lst->content), content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
