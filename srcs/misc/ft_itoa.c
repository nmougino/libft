/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:23:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/12 18:40:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_doit(char *ans, size_t len, int nb)
{
	size_t	i;

	i = 0;
	ans[len] = '\0';
	if (nb < 0)
	{
		ans[i] = '-';
		nb *= -1;
		++i;
	}
	--len;
	while (i <= len)
	{
		ans[len] = (nb % 10) + '0';
		nb /= 10;
		--len;
	}
}

char		*ft_itoa(int nb)
{
	char	*ans;
	size_t	len;

	ans = NULL;
	len = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(nb);
	if (!(ans = malloc((sizeof(char)) * (len + 1))))
		return (NULL);
	ft_itoa_doit(ans, len, nb);
	return (ans);
}
