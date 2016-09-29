/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:11:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 02:47:22 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	uitoabase(uintmax_t p, char *base, t_print *print, size_t l)
{
	char	c[l + 1];
	char	baselen;

	baselen = ft_strlen(base);
	c[l] = 0;
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
