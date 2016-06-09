/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:06:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/06/09 17:32:58 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlenbase(int nb, int base)
{
	int		i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > base)
	{
		i++;
		nb /= base;
	}
	return (i);
}
