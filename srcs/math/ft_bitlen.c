/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:54:40 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 12:59:59 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_bitlen(uintmax_t p)
{
	uintmax_t	tmp;
	size_t		i;

	tmp = p;
	i = 0;
	while (tmp && ++i)
		tmp = tmp >> 1;
	if (!i)
		return (1);
	return (i);
}
