/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:08:56 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/02 13:40:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_u(t_spec *spec, t_print *print)
{
	uintmax_t	p;

	p = urecupparam(spec->hljz, print->ap);
	if (!(!p && !spec->prec))
	{
		(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw -
			(ft_max(spec->prec, ft_nbrlenbase(p, 10)))) : 0;
		applynumprec(print, spec, ft_nbrlenbase(p, 10));
		uitoabase(p, "0123456789", print, ft_nbrlenbase(p, 10));
		(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw) : 0;
	}
}

void	conv_lu(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'u';
	conv_u(spec, print);
}
