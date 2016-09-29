/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:06:19 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:25:14 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ans;

	ans = s;
	while (n--)
	{
		if (*ans == (const unsigned char)c)
			return ((void *)((unsigned long)(ans)));
		++ans;
	}
	return (NULL);
}
