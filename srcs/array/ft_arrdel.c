/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:22:42 by nmougino          #+#    #+#             */
/*   Updated: 2017/04/13 18:10:20 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(void **tab)
{
	void	**tmp;

	tmp = tab;
	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(*tmp);
	free(tab);
}
