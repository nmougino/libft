/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:20:08 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/23 18:32:42 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Integration de fork(2) avec affichage de l'erreur.
** 'parent' est le nom du logiciel appelant.
*/

pid_t	ft_fork(char *parent)
{
	pid_t	p;
	char	*str;

	str = NULL;
	if ((p = fork()) == -1)
	{
		str = (errno == EAGAIN) ? FORK_EAGAIN : str;
		str = (errno == ENOMEM) ? FORK_ENOMEM : str;
		str = !str ? "Unknow error, please check errno" : str;
		ft_printf("%s: fork error: %s\n", parent, str);
		exit(-1);
	}
	return (p);
}
