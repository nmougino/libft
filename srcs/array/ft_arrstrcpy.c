/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:50:37 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/30 19:01:20 by nmougino         ###   ########.fr       */
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
	while (src[i])
	{
		tab[i] = src[i];
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
