/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:18:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/19 16:58:01 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned long i;

	i = 0;
	while ((s[i] != (char)c) && s[i])
		i++;
	if (s[i] == (char)c)
		return (char *)((unsigned long)s + i);
	return (NULL);
}
