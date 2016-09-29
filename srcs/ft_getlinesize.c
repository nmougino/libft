/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinesize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 05:13:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:06:15 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getlinesize(char *buf)
{
	size_t	ans;

	ans = 0;
	while (*buf && *buf != '\n')
	{
		ans++;
		buf++;
	}
	return (ans);
}
