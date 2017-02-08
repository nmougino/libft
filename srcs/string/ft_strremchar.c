/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:03:53 by nmougino          #+#    #+#             */
/*   Updated: 2017/02/08 22:09:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Supprime le caractere en position pos
** ATTENTION
** ft_strremchar ne realloc pas la chaine, les octets de fin
** existerons toujours si src a ete malloce, ceci dans un soucis
** de pouvoir etre utilisee sur des chaines statiques.
*/

void	ft_strremchar(char **src, size_t pos)
{
	if (pos < ft_strlen(*src))
	{
		while ((*src)[pos])
		{
			(*src)[pos] = (*src)[pos + 1];
			++pos;
		}
	}
}
