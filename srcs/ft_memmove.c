/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:16:55 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:28:02 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (src < dst)
		while (i--)
			*((unsigned char*)((unsigned long)dst + i)) =
				*((const unsigned char*)((unsigned long)src + i));
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)((unsigned long)dst + i)) =
				*((const unsigned char*)((unsigned long)src + i));
			++i;
		}
	}
	return (dst);
}
