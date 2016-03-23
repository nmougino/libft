/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotoline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 04:17:56 by nmougino          #+#    #+#             */
/*   Updated: 2016/01/25 03:39:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gotoline(char *buf, int l)
{
	int		i;

	i = 0;
	if (l > 0)
	{
		while (i < l && *buf != '\0')
		{
			if (*buf == '\n')
				i++;
			buf++;
		}
	}
	return (buf);
}
