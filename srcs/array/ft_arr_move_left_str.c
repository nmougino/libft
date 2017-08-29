/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_move_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 12:46:31 by nmougino          #+#    #+#             */
/*   Updated: 2017/08/29 12:55:05 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_move_left_str(char **arr)
{
	int		i;
	char	*tmp;

	if (!arr || !(*arr))
		return ;
	i = -1;
	tmp = arr[0];
	while (arr[++i])
		arr[i] = arr[i + 1];
	ft_strdel(&tmp);
}
