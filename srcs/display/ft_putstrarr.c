/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:39:39 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/30 18:49:10 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **arr)
{
	int		i;

	i = 0;
	while (*arr)
	{
		ft_putnbr(i);
		ft_putstr("  : |");
		ft_putstr(*arr);
		ft_putendl("|");
		++arr;
		++i;
	}
}
