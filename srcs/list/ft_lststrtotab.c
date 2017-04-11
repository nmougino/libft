/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrtotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:16:32 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/11 17:47:47 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lststrtotab(t_list *lst)
{
	char			**tab;
	size_t			p;

	tab = malloc(sizeof(char*) * (ft_lstlen(lst) + 1));
	if (!(tab))
		return (NULL);
	p = 0;
	while (lst)
	{
		tab[p++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	tab[p] = NULL;
	return (tab);
}
