/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbrline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:17:02 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:06:41 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbrline(char *buf)
{
	int		ans;
	int		i;

	ans = 0;
	i = 0;
	if (buf[i])
		ans++;
	while (buf[i])
	{
		if (buf[i] == '\n')
			ans++;
		i++;
	}
	return (ans);
}
