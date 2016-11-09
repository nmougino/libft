/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 06:51:11 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:03:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ans;

	i = 0;
	while (dst[i] && i < size)
		++i;
	ans = i;
	while (src[i - ans] && i < (size - 1))
	{
		dst[i] = src[i - ans];
		++i;
	}
	if (ans < size)
		dst[i] = '\0';
	return (ans + ft_strlen(src));
}
