/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:01:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:38:47 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (!(ans = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ans[i] = s[start + i];
		++i;
	}
	ans[i] = '\0';
	return (ans);
}
