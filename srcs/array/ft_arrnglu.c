/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnglu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 18:00:22 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/20 17:51:59 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** size correspond a la taille en octet du separateur
** n au nombre d'elements a copier
*/

static size_t	sizetabcount(char **arg, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (arg[i] && n--)
	{
		j += (ft_strlen(arg[i]));
		++i;
	}
	return (j);
}

char			*ft_arrnglu(char **arg, char *separator, size_t size, size_t n)
{
	char	*str;
	size_t	i;
	size_t	l;

	if (!n)
		return (ft_strdup(""));
	l = ((size && separator) ? (n - 1) * size : 0) + sizetabcount(arg, n);
	if (!(str = ft_strnew(l)))
		return (NULL);
	i = 0;
	while (arg[i] && n--)
	{
		ft_strcat(str, arg[i]);
		if (arg[i + 1])
			ft_strncat(str, separator, size);
		++i;
	}
	return (str);
}
