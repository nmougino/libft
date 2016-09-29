/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:07:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/02 12:30:53 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_x(t_spec *spec, t_print *print)
{
	intmax_t	i;
	intmax_t	j;
	uintmax_t	p;

	p = urecupparam(spec->hljz, print->ap);
	i = ((spec->flags & E_SHARP && !(spec->flags & E_ZERO)) ? 2 : 0);
	i -= (p == 0 && spec->flags & E_SHARP) ? 2 : 0;
	j = !(spec->prec || p) ? 0
		: (i + ft_max(spec->prec, (intmax_t)ft_nbrlenbase(p, 16)));
	if (spec->flags & E_ZERO && p)
		applysharp(print, spec);
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, (intmax_t)spec->mfw - j);
	if (!(spec->flags & E_ZERO) && p)
		applysharp(print, spec);
	applynumprec(print, spec, ft_nbrlenbase(p, 16));
	if (spec->prec || p)
		uitoabase(p, "0123456789abcdef", print, ft_nbrlenbase(p, 16));
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}

void	conv_bx(t_spec *spec, t_print *print)
{
	intmax_t	i;
	intmax_t	j;
	uintmax_t	p;

	p = urecupparam(spec->hljz, print->ap);
	i = ((spec->flags & E_SHARP && !(spec->flags & E_ZERO)) ? 2 : 0);
	i -= (p == 0 && spec->flags & E_SHARP) ? 2 : 0;
	j = !(spec->prec || p) ? 0
		: (i + ft_max(spec->prec, (intmax_t)ft_nbrlenbase(p, 16)));
	if (spec->flags & E_ZERO && p)
		applysharp(print, spec);
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, (intmax_t)spec->mfw - j);
	if (!(spec->flags & E_ZERO) && p)
		applysharp(print, spec);
	applynumprec(print, spec, ft_nbrlenbase(p, 16));
	if (spec->prec || p)
		uitoabase(p, "0123456789ABCDEF", print, ft_nbrlenbase(p, 16));
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}
