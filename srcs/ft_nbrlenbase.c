/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:06:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 17:38:47 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlenbase(uintmax_t nb, int base)
{
	double	tmp;
	size_t	i;

	i = 1;
	tmp = (double)nb;
	while (tmp >= (uintmax_t)base)
	{
		++i;
		tmp /= base;
	}
	return (i);
}
