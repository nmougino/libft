/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:13:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/12 17:57:35 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	register unsigned char	*t;

	t = (unsigned char*)s;
	while (n > 8)
	{
		*(unsigned long *)((unsigned long)t) = 0;
		t += 8;
		n -= 8;
	}
	while (n--)
	{
		*t = 0;
		++t;
	}
}
