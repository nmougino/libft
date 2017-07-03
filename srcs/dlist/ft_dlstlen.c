/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:23:47 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/03 21:24:31 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstlen(t_dlist *lst)
{
	size_t	ans;

	ans = 0;
	while (lst)
	{
		++ans;
		lst = lst->next;
	}
	return (ans);
}
