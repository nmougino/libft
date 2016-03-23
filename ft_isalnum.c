/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:54:44 by nmougino          #+#    #+#             */
/*   Updated: 2015/11/25 11:03:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int ans;

	ans = 0;
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		ans = 1;
	return (ans);
}
