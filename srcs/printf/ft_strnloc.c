/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 20:08:27 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 13:38:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnloc(char c, char *ptr, int n)
{
	int		i;

	i = 0;
	while (n--)
	{
		if ((char)ptr[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
