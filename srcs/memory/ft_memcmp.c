/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:53:53 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/19 16:45:11 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sa;
	const unsigned char	*sb;

	sa = (const unsigned char*)s1;
	sb = (const unsigned char*)s2;
	while (n--)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		++sa;
		++sb;
	}
	return (0);
}
