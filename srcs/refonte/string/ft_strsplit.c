/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:20:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 21:39:25 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_nb_word(const char *s, char c)
{
	size_t	i;
	int		isword;

	i = 0;
	isword = 0;
	while (*s)
	{
		if (isword == 0 && *s != c)
		{
			isword = 1;
			i++;
		}
		else if (isword == 1 && *s == c)
			isword = 0;
		s++;
	}
	return (i);
}

static size_t	ft_length_word(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	size_t	nbword;

	i = 0;
	nbword = ft_nb_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (!tab)
		return (NULL);
	while (nbword--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, ft_length_word(s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_length_word(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
