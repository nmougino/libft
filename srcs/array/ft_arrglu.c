/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrglu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 18:00:22 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/20 17:45:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** size correspond a la taille en octet du separateur
*/

static size_t	sizetabcount(char **arg)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		j += (ft_strlen(arg[i]));
		++i;
	}
	return (j);
}

char			*ft_arrglu(char **arg, char *separator, size_t size)
{
	char	*str;
	size_t	arrlen;
	size_t	i;
	size_t	l;

	arrlen = ft_arrlen(arg, sizeof(char *));
	l = ((size && separator) ? (arrlen - 1) * size : 0) + sizetabcount(arg);
	if (!(str = ft_strnew(l)))
		return (NULL);
	i = 0;
	while (arg[i])
	{
		ft_strcat(str, arg[i]);
		if (arg[i + 1])
			ft_strncat(str, separator, size);
		++i;
	}
	return (str);
}
