/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:18:04 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/31 16:56:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long i;

	i = 0;
	while (s[i] && (s[i] != (char)c))
		i++;
	if (s[i] && s[i] == (char)c)
		return (char *)((unsigned long)s + i);
	return (NULL);
}
