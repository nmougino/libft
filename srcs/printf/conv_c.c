/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:06:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 14:31:45 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_spec *spec, t_print *print)
{
	intmax_t	p;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'C';
		conv_lc(spec, print);
	}
	else
	{
		p = recupparam(spec->hljz, print->ap);
		if (!(spec->flags & E_DASH))
			applymfw(print, spec, spec->mfw - 1);
		addto((char)p, print);
		if (spec->flags & E_DASH)
			applymfw(print, spec, spec->mfw);
	}
}
