/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:36:41 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 21:25:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue une nouvelle chaine resultante de la copie de s
** nettoyee des caracteres blanc ' ', '\t', '\n' en debut et fin de chaine.
*/

char	*ft_strtrim(char const *s)
{
	unsigned long	q;
	unsigned long	o;

	o = 0;
	q = 0;
	if (s != NULL && s[0] != '\0')
	{
		q = ft_strlen(s) - 1;
		while (s[o] == ' ' || s[o] == '\t' || s[o] == '\n')
			o++;
		if (s[o + 1] == '\0')
			return (NULL);
		while ((s[q] == ' ' || s[q] == '\t' || s[q] == '\n') && q > 0)
			q--;
		if (q == 0)
			return (ft_strdup(""));
		if (o < q)
			return (ft_strsub(s, (unsigned int)o, (q + 1 - o)));
	}
	if (s[0] == '\0')
		return (ft_strdup(""));
	return (NULL);
}
