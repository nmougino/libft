/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:06:03 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/06 02:08:02 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cree une copie de la chaine src en inserant la chaine cut
** en position pos (0 en premier).
*/

void	ft_strinsstr(char **src, char *cut, size_t pos)
{
	char	*out;
	size_t	len;

	if (pos < ft_strlen(*src))
	{
		len = ft_strlen(*src) + ft_strlen(cut);
		if ((out = ft_strnew(len)))
		{
			ft_strncpy(out, *src, pos);
			ft_strcpy(out + pos, cut);
			ft_strcpy(out + pos + ft_strlen(cut), *src + pos);
			free(*src);
			*src = out;
		}
	}
}
