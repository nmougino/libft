/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:27:08 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:10:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre pour créer une nouvelle chaine allouee
** résultant des applications successives de f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ans;

	i = 0;
	if (!(ans = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		ans[i] = f(s[i]);
		++i;
	}
	ans[i] = '\0';
	return (ans);
}
