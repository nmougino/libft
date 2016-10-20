/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:29:24 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 15:19:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Inverse en place chaque caractere de la chaine passee en parametre.
** Renvoie le pointeur sur le premier caractere de la chaine.
*/

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	mid;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	mid = len / 2;
	--len;
	while (i < mid)
		ft_swapchar(str + i++, str + len--);
	return (str);
}
