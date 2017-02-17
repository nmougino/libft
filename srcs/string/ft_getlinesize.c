/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinesize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:28:20 by nmougino          #+#    #+#             */
/*   Updated: 2017/02/17 17:40:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getlinesize(char *buf)
{
	size_t		ans;

	ans = 0;
	while (*buf && *buf != '\n')
	{
		++ans;
		++buf;
	}
	return (ans);
}
