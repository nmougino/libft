/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:29:08 by nmougino          #+#    #+#             */
/*   Updated: 2017/02/17 17:42:19 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getlline(char *buf, int l)
{
	char	*ans;
	int		i;

	i = 0;
	buf = ft_gotoline(buf, l);
	ans = ft_strnew(ft_getlinesize(buf) + 1);
	while (buf[i] && buf[i] != '\n')
	{
		ans[i] = buf[i];
		i++;
	}
	return (ans);
}
