/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 21:37:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/10/29 17:24:50 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrt(float nb)
{
	float	xhalf;
	int		i;

	i = *(int*)&nb;
	xhalf = 0.5f * nb;
	i = 0x5f3759df - (i >> 1);
	nb = *(float*)&i;
	nb = nb * (1.5f - xhalf * nb * nb);
	return (nb);
}
