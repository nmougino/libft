/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:26:09 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/07 18:44:34 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isup(int c)
{
	int	ans;

	ans = 0;
	if (c >= 'A' && c <= 'Z')
		ans = 1;
	return (ans);
}