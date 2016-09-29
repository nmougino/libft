/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:11:09 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 02:44:01 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sitoa(intmax_t p, t_print *print, size_t l)
{
	char	c[l + 1];

	c[l] = 0;
	p = ft_abs(p);
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
