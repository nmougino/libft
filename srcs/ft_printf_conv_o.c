/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:08:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/06/20 18:54:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_o(t_spec *spec, t_print *print)
{
	uintmax_t	i;
	uintmax_t	p;
	int			j;
	intmax_t	k;

	p = urecupparam(spec->hljz, print->ap);
	i = (spec->flags & E_SHARP && !(spec->flags & E_ZERO));
	if (spec->flags & E_ZERO)
		applysharp(print, spec);
	j = ((spec->prec == -1) ? (int)i : 0);
	k = !(spec->prec || p) ? 0
		: ((intmax_t)j + ft_max(spec->prec, (intmax_t)ft_nbrlenbase(p, 8)));
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - k);
	if (!(spec->flags & E_ZERO))
		applysharp(print, spec);
	applynumprec(print, spec, i + ft_nbrlenbase(p, 8));
	if (spec->prec || p)
		uitoabase(p, "01234567", print, ft_nbrlenbase(p, 8));
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}

void	conv_lo(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'o';
	conv_o(spec, print);
}
