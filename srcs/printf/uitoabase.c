/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoabase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:11:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 14:17:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uitoabase(uintmax_t p, char *base, t_print *print, size_t l)
{
	size_t	baselen;
	char	c[50];

	ft_bzero(c, 50);
	baselen = ft_strlen(base);
	while (l--)
	{
		c[l] = base[p % baselen];
		p /= baselen;
	}
	l = 0;
	while (c[l])
	{
		addto(c[l], print);
		++l;
	}
}
