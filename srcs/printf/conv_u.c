/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:08:56 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 15:22:17 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_u(t_spec *spec, t_print *print)
{
	uintmax_t	p;

	p = urecupparam(spec->hljz, print->ap);
	if (!(!p && !spec->prec))
	{
		if (!(spec->flags & E_DASH))
			applymfw(print, spec, spec->mfw -
			(ft_max(spec->prec, (int)ft_nbrlenbasemax(p, 10))));
		applynumprec(print, spec, (int)ft_nbrlenbasemax(p, 10));
		uitoabase(p, "0123456789", print, ft_nbrlenbasemax(p, 10));
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw);
	}
}

void	conv_lu(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'u';
	conv_u(spec, print);
}
