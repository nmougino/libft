/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:45:26 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/31 20:41:26 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare lexicographiquement s1 et s2. Si les deux chaines
** sont égales, la fonction retourne 1, ou 0 sinon.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1)
	{
		if (!s2)
			return (1);
		return (0);
	}
	if (!s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
