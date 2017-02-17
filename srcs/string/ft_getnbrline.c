/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbrline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:30:53 by nmougino          #+#    #+#             */
/*   Updated: 2017/02/17 17:39:42 by nmougino         ###   ########.fr       */
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
