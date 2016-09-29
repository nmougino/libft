/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:08:12 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:41:12 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_o(t_printf_spec *spec, t_print *print)
{
	int			i;
	uintmax_t	p;
	int			j;
	int			k;

	p = urecupparam(spec->hljz, print->ap);
	i = (spec->flags & E_SHARP && !(spec->flags & E_ZERO));
	(spec->flags & E_ZERO) ? applysharp(print, spec) : 0;
	j = ((spec->prec == -1) ? i : 0);
	k = !(spec->prec || p) ? 0 : (j + ft_max(spec->prec, ft_nbrlenbase(p, 8)));
	(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw - k) : 0;
	(!(spec->flags & E_ZERO)) ? applysharp(print, spec) : 0;
	applynumprec(print, spec, i + ft_nbrlenbase(p, 8));
	!(spec->prec || p) ? 0
		: uitoabase(p, "01234567", print, ft_nbrlenbase(p, 8));
	(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw) : 0;
}

void	conv_lo(t_printf_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'o';
	conv_o(spec, print);
}
