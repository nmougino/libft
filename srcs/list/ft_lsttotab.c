/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:18:05 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/10 19:28:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lsttotab(t_list *lst)
{
	void			**tab;
	size_t			p;

	tab = malloc(sizeof(void*) * (ft_lstlen(lst) + 1));
	if (!(tab))
		return (NULL);
	p = 0;
	while (lst)
	{
		tab[p++] = lst->content;
		lst = lst->next;
	}
	tab[p] = NULL;
	return (tab);
}
