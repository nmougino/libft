/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 20:08:27 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/20 17:17:01 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcloc(char c, char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
	{
		if ((char)ptr[i] == c)
			return (i);
		++i;
	}
	return (-1);
}