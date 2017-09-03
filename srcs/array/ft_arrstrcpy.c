/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:50:37 by nmougino          #+#    #+#             */
/*   Updated: 2017/09/03 20:59:22 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrstrcpy(char **src)
{
	char	**tab;
	int		i;

	if (!(tab = malloc(sizeof(char *) * (ft_arrlen(src, sizeof(char *)) + 1))))
		return (NULL);
	i = 0;
	while (src && src[i])
	{
		tab[i] = ft_strdup(src[i]);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
