/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:02:20 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/30 18:13:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Renvoie le tableau de char * resultant de la concatenation de a1 et a2
*/

char	**ft_arrcat(char **a1, char **a2)
{
	char	**a;
	int		i;

	if (!(a = malloc(sizeof(char **) * (ft_arrlen(a1, sizeof(char*))
		+ ft_arrlen(a2, sizeof(char*)) + 1))))
		return (NULL);
	i = 0;
	while (*a1)
	{
		a[i] = ft_strdup(*a1);
		++a1;
		++i;
	}
	while (*a2)
	{
		a[i] = ft_strdup(*a2);
		++a1;
		++i;
	}
	a[i] = NULL;
	return (a);
}
