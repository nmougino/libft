/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:06:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/06/10 18:43:37 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlenbase(unsigned long nb, int base)
{
	int		i;

	i = 1;
	while (nb > (unsigned long)base)
	{
		i++;
		nb /= base;
	}
	return (i);
}
