/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:49:59 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/31 20:42:29 by nmougino         ###   ########.fr       */
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
	if (!n)
		return (1);
	if (!s1)
	{
		if (!s2)
			return (1);
		return (0);
	}
	if (!s2)
		return (0);
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		++i;
	if (i < n)
		return (0);
	return (1);
}
