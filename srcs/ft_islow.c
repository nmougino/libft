/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:33:52 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/04 20:51:22 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islow(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}
