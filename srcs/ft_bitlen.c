/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:54:40 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/04 17:28:07 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bitlen(intmax_t p)
{
	intmax_t	tmp;
	int			i;

	tmp = p;
	i = 0;
	while (tmp && ++i)
		tmp = tmp >> 1;
	if (!i)
		return (1);
	return (i);
}
