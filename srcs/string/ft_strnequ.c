/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:49:59 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 15:23:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare lexicographiquement s1 et s2 sur n caracteres.
** Si les deux chaines sont égales, la fonction retourne 1, ou 0 sinon.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	if (s1[i - 1] != s2[i - 1])
		return (0);
	return (1);
}
