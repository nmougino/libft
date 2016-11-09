/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:05:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 14:41:26 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(t_spec *spec, t_print *print)
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
		s = (char *)(unsigned long)urecupparam(E_LONG, print->ap);
		if (!s)
			s = "(null)";
		neg = (spec->prec > -1 ? (size_t)ft_min(spec->prec, (int)ft_strlen(s)) :
				ft_strlen(s));
		if (!(spec->flags & E_DASH))
			applymfw(print, spec, (spec->mfw) - (int)neg);
		while (s[i] && (spec->prec--))
			addto(s[i++], print);
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw);
	}
}
