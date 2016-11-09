/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 06:34:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 15:31:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Prend en paramètre l’adresse d’une chaine de caractères qui
** doit être libérée avec free(3) et son pointeur mis à NULL.
*/

void	ft_strdel(char **as)
{
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
}
