/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:16:55 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/21 00:38:59 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (src < dst)
		while (i--)
			*((unsigned char*)((unsigned long)dst + (unsigned long)i)) =
				*((unsigned char*)(unsigned long)src + (unsigned long)i);
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)((unsigned long)dst + (unsigned long)i)) =
			*((unsigned char*)((unsigned long)src + (unsigned long)i));
			++i;
		}
	}
	return (dst);
}
