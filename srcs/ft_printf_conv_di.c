/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:07:26 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 03:11:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conv_d_applypreparam(t_printf_spec *spec, t_print *print
	, intmax_t p)
{
	intmax_t	i;
	intmax_t	j;

	i = (p < 0) || (spec->flags & 3);
	j = !(spec->prec || p) ? 0 : (ft_max((intmax_t)spec->prec + i,
	(intmax_t)ft_nbrlen((intmax_t)ft_abs(p) + i)));
	++spec->mfw;
	if (spec->flags & E_ZERO)
		applyplusspace(print, spec, p >= 0);
	else
		--spec->mfw;
	if (spec->flags & E_ZERO && p > 0)
		--spec->prec;
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - (int)j);
	if (!(spec->flags & E_ZERO))
		applyplusspace(print, spec, p >= 0);
	applynumprec(print, spec, ft_nbrlen((intmax_t)ft_abs(p)));
}

void	conv_d(t_printf_spec *spec, t_print *print)
{
	intmax_t	p;
	int			j;

	p = recupparam(spec->hljz, print->ap);
	if (p > -9223372036854775807)
	{
		conv_d_applypreparam(spec, print, p);
		if (!(!spec->prec && !p))
			sitoa(p, print, ft_nbrlen((intmax_t)ft_abs(p)));
		j = (spec->flags & 3) && (p > 0);
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw + (p >= 0) - j);
	}
}

void	conv_i(t_printf_spec *spec, t_print *print)
{
	intmax_t	p;
	int			j;

	p = recupparam(spec->hljz, print->ap);
	if (p > -9223372036854775807)
	{
		conv_d_applypreparam(spec, print, p);
		if (!(!spec->prec && !p))
			sitoa(p, print, ft_nbrlen((intmax_t)ft_abs(p)));
		j = (spec->flags & 3) && (p > 0);
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw + (p >= 0) - j);
	}
}

void	conv_ld(t_printf_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'd';
	conv_d(spec, print);
}
