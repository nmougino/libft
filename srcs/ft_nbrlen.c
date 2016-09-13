/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:39:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/04 17:28:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(intmax_t nb)
{
	int		i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		++i;
	}
	while (nb > 9)
	{
		++i;
		nb /= 10;
	}
	return (i);
}
