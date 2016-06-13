/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlenbin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:48:29 by nmougino          #+#    #+#             */
/*   Updated: 2016/06/13 15:55:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlenbin(long p)
{
	long	tmp;
	int		i;

	tmp = p;
	i = 0;
	while (tmp && ++i)
		tmp = tmp >> 1;
	return (i);
}
