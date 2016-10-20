/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:02:21 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:41:17 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*s;

	s = (char *)((unsigned long)s1);
	len = ft_strlen(s2);
	if (!(*s2))
		return (s);
	while (*s && n-- >= len)
	{
		if (*s == *s2 && ft_memcmp(s, s2, len) == 0)
			return (s);
		++s;
	}
	return (NULL);
}
