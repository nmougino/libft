/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:07:26 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/12 17:55:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	di_tmp(t_spec *sp, t_print *pr, intmax_t p)
{
	if (sp->flags & E_ZERO)
		applyplusspace(pr, sp, p >= 0);
	else
		--sp->mfw;
}

void		conv_d(t_spec *sp, t_print *pr)
{
	int			i;
	int			j;
	intmax_t	p;
	int			l;

	if (!((p = recupparam(sp->hljz, pr->ap)) > -9223372036854775807))
		return ;
	l = (int)ft_nbrlenmax(ft_absmax(p));
	i = (p < 0) || (sp->flags & 3);
	j = !(sp->prec || p) ? 0 : (ft_max(sp->prec + i, (int)l + i));
	++sp->mfw;
	di_tmp(sp, pr, p);
	(sp->flags & E_ZERO && p > 0) ? --sp->prec : 0;
	if (!(sp->flags & E_DASH))
		applymfw(pr, sp, sp->mfw - j);
	if (!(sp->flags & E_ZERO))
		applyplusspace(pr, sp, p >= 0);
	applynumprec(pr, sp, l);
	if (!(!sp->prec && !p))
		sitoa(p, pr, (size_t)l);
	if (sp->flags & E_DASH)
		applymfw(pr, sp, sp->mfw + (p >= 0) - (sp->flags & 3) && (p > 0));
}

void		conv_i(t_spec *sp, t_print *pr)
{
	int			i;
	int			j;
	intmax_t	p;
	int			l;

	if (!((p = recupparam(sp->hljz, pr->ap)) > -9223372036854775807))
		return ;
	l = (int)ft_nbrlenmax(ft_absmax(p));
	i = (p < 0) || (sp->flags & 3);
	j = !(sp->prec || p) ? 0 : (ft_max(sp->prec + i, (int)l + i));
	++sp->mfw;
	di_tmp(sp, pr, p);
	(sp->flags & E_ZERO && p > 0) ? --sp->prec : 0;
	if (!(sp->flags & E_DASH))
		applymfw(pr, sp, sp->mfw - j);
	if (!(sp->flags & E_ZERO))
		applyplusspace(pr, sp, p >= 0);
	applynumprec(pr, sp, l);
	if (!(!sp->prec && !p))
		sitoa(p, pr, (size_t)l);
	if (sp->flags & E_DASH)
		applymfw(pr, sp, sp->mfw + (p >= 0) - (sp->flags & 3) && (p > 0));
}

void		conv_ld(t_spec *sp, t_print *print)
{
	sp->hljz = ((sp->flags == E_L) ? E_LL : E_L);
	sp->conv = 'd';
	conv_d(sp, print);
}
