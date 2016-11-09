/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:11:09 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 14:16:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sitoa(intmax_t p, t_print *print, size_t l)
{
	char	c[50];

	ft_bzero(c, 50);
	p = ft_absmax(p);
	while (l--)
	{
		c[l] = p % 10 + '0';
		p /= 10;
	}
	l = 0;
	while (c[l])
	{
		addto(c[l], print);
		++l;
	}
}
