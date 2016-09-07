/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strglu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 18:00:22 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 19:02:38 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tabcount(const char **arg)
{
	register size_t	i;

	i = 0;
	while (arg[i])
		++i;
	return (i - 1);
}

static size_t	sizetabcount(const char **arg)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		j += (ft_strlen(arg[i]));
		++i;
	}
	return (j);
}

char			*ft_strglu(const char **arg, char separator)
{
	char			*ans;
	const size_t	size = tabcount(arg);
	register size_t	i;
	register int	j;
	register int	k;

	i = 0;
	k = 0;
	ans = (char *)malloc(sizeof(char) * ((separator >= 0 ? size : 0)
				+ sizetabcount(arg) + 1));
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
			ans[k++] = arg[i][j++];
		if (separator >= 0 && i < size)
			ans[k++] = separator;
		++i;
	}
	ans[k] = 0;
	return (ans);
}
