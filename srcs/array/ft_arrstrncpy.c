/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:50:37 by nmougino          #+#    #+#             */
/*   Updated: 2017/09/03 21:30:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrstrncpy(char **src, size_t n)
{
	char	**tab;
	size_t	i;

	if (!(tab = malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	while (src && src[i] && i < n)
	{
		tab[i] = ft_strdup(src[i]);
		++i;
	}
	while (i <= n)
	{
		tab[i] = NULL;
		++i;
	}
	return (tab);
}
