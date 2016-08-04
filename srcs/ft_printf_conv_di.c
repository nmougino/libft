/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:07:26 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/02 13:47:44 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_d(t_spec *spec, t_print *print)
{
	int			i;
	int			j;
	intmax_t	p;

	p = recupparam(spec->hljz, print->ap);
	if (p > -9223372036854775807)
	{
		i = (p < 0) || (spec->flags & 3);
		j = !(spec->prec || p) ? 0
			: (ft_max(spec->prec + i, ft_nbrlen(ft_abs(p)) + i));
		++spec->mfw;
		(spec->flags & E_ZERO) ? applyplusspace(print, spec, p >= 0)
			: --spec->mfw;
		(spec->flags & E_ZERO && p > 0) ? --spec->prec : 0;
		(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw - j) : 0;
		!(spec->flags & E_ZERO) ? applyplusspace(print, spec, p >= 0) : 0;
		applynumprec(print, spec, ft_nbrlen(ft_abs(p)));
		(!spec->prec && !p) ? 0 : sitoa(p, print, ft_nbrlen(ft_abs(p)));
		j = (spec->flags & 3) && (p > 0);
		(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw +
			(p >= 0) - j) : 0;
	}
}

void	conv_i(t_spec *spec, t_print *print)
{
	int			i;
	int			j;
	intmax_t	p;

	p = recupparam(spec->hljz, print->ap);
	if (p > -9223372036854775807)
	{
		i = (p < 0) || (spec->flags & 3);
		j = !(spec->prec || p) ? 0
			: (ft_max(spec->prec + i, ft_nbrlen(ft_abs(p)) + i));
		++spec->mfw;
		(spec->flags & E_ZERO) ? applyplusspace(print, spec, p >= 0)
			: --spec->mfw;
		(spec->flags & E_ZERO && p > 0) ? --spec->prec : 0;
		(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw - j) : 0;
		!(spec->flags & E_ZERO) ? applyplusspace(print, spec, p >= 0) : 0;
		applynumprec(print, spec, ft_nbrlen(ft_abs(p)));
		(!spec->prec && !p) ? 0 : sitoa(p, print, ft_nbrlen(ft_abs(p)));
		j = (spec->flags & 3) && (p > 0);
		(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw +
			(p >= 0) - j) : 0;
	}
}

void	conv_ld(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'd';
	conv_d(spec, print);
}
