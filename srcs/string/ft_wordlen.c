/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 00:18:36 by nmougino          #+#    #+#             */
/*   Updated: 2017/07/12 20:38:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char *str, char *seps)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr(seps, str[i]))
		++i;
	return (i);
}