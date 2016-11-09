/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:45:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;

	i = ft_strlen(s);
	while ((s[i] != (char)c) && i)
		--i;
	if (s[i] == (char)c)
		return ((char*)((unsigned long)s + i));
	return (NULL);
}
