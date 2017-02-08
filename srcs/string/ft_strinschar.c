/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinschar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:06:03 by nmougino          #+#    #+#             */
/*   Updated: 2017/02/08 22:09:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cree une copie de la chaine src en inserant c
** en position pos (0 en premier).
*/

void	ft_strinschar(char **src, size_t pos, char c)
{
	char	*out;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(*src) + 1;
	out = ft_strnew(len);
	if (out)
	{
		while (i < len)
		{
			if (i == pos)
				out[i] = c;
			else if (i > pos)
				out[i] = (*src)[i - 1];
			else if (i < pos)
				out[i] = (*src)[i];
			++i;
		}
		free(*src);
		*src = out;
	}
}
