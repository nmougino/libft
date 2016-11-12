/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:36:41 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/12 17:54:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue une nouvelle chaine resultante de la copie de s
** nettoyee des caracteres blanc ' ', '\t', '\n' en debut et fin de chaine.
*/

char	*ft_strtrim(const char *s)
{
	int		i;
	char	*ret;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		--i;
	++i;
	ret = ft_strnew(i);
	ft_strncpy(ret, s, i);
	return (ret);
}
