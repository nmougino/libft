/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:26:40 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 20:52:02 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	char	*s;

	s = (char *)((unsigned long)s1);
	len = ft_strlen(s2);
	if (!(*s2))
		return (s);
	while (*s)
	{
		if (*s == *s2 && ft_memcmp(s, s2, len) == 0)
			return (s);
		++s;
	}
	return (NULL);
}
