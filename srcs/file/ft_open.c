/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:11 by nmougino          #+#    #+#             */
/*   Updated: 2017/09/04 21:35:23 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Cette fonction a le comportement d'open tout en gerant les posibles erreurs
** a l'ouverture du fichier.
** Elle envoie alors le message d'erreur approprie le cas echeant.
*/

static char	*errstr(void)
{
	char	*str;

	str = NULL;
	str = (errno == EACCES) ? STR_EACCES : str;
	str = (errno == EDQUOT) ? STR_EDQUOT : str;
	str = (errno == EEXIST) ? STR_EEXIST : str;
	str = (errno == EINVAL) ? STR_EINVAL : str;
	str = (errno == EIO) ? STR_EIO : str;
	str = (errno == EISDIR) ? STR_EISDIR : str;
	str = (errno == ELOOP) ? STR_ELOOP : str;
	str = (errno == EMFILE) ? STR_EMFILE : str;
	str = (errno == ENAMETOOLONG) ? STR_ENAMETOOLONG : str;
	str = (errno == ENOENT) ? STR_ENOENT : str;
	str = (errno == ENOSPC) ? STR_ENOSPC : str;
	str = (errno == ENOTDIR) ? STR_ENOTDIR : str;
	str = (errno == ENXIO) ? STR_ENXIO : str;
	str = (errno == EOPNOTSUPP) ? STR_EOPNOTSUPP : str;
	str = (errno == EOVERFLOW) ? STR_EOVERFLOW : str;
	str = (errno == EROFS) ? STR_EROFS : str;
	str = (errno == ETXTBSY) ? STR_ETXTBSY : str;
	str = (errno == EBADF) ? STR_EBADF : str;
	str = (errno == ENOTDIR) ? STR_ENOTDIR : str;
	str = str ? str : "Unknow error, please check errno";
	return (str);
}

int			ft_open(char *path, int flag, int perm, char *parent)
{
	int	i;

	i = open(path, flag, perm);
	if (i == -1)
		ft_dprintf(2, "%s : %s : %s\n", parent, path, errstr());
	return (i);
}
