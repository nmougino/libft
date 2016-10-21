/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:29:24 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/21 13:38:34 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f sur tous les elements de la liste
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		f(cur);
		cur = cur->next;
	}
}
