/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:05:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 18:03:26 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_s(t_printf_spec *spec, t_print *print)
{
	int		i;
	size_t	neg;
	char	*s;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'S';
		conv_ls(spec, print);
	}
	else
	{
		i = 0;
		s = (char *)((unsigned long)urecupparam(E_LONG, print->ap));
		if (!s)
			s = "(null)";
		neg = (spec->prec > -1 ?
			(size_t)ft_min(spec->prec, (intmax_t)ft_strlen(s)) : ft_strlen(s));
		if (!(spec->flags & E_DASH))
			applymfw(print, spec, (intmax_t)((size_t)spec->mfw - neg));
		while (s[i] && (spec->prec--))
			addto(s[i++], print);
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw);
	}
}
