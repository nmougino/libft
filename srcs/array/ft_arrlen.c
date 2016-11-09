/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:09:10 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/19 18:11:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compte le nombre d'element dans un tableau terminant par un element NULL.
** type equivaut a la taille en octet du type du tableau.
*/

size_t	ft_arrlen(void *a, size_t type)
{
	char			i;
	size_t			c;
	size_t			l;
	char			*arr;

	i = 1;
	c = 0;
	l = 0;
	arr = (char *)a;
	while (i)
	{
		while (l < type && !arr[l])
			++l;
		if (l < type)
		{
			arr += type;
			++c;
		}
		else
			i = 0;
	}
	return (c);
}
