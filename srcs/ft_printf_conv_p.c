/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:06:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 17:57:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_p(t_printf_spec *spec, t_print *print)
{
	intmax_t	j;
	uintmax_t	p;

	spec->hljz = E_L;
	p = urecupparam(spec->hljz, print->ap);
	j = !(spec->prec || p) ? 0
		: (ft_max(spec->prec, (intmax_t)ft_nbrlenbase(p, 16) + 2));
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - j);
	addto('0', print);
	addto('x', print);
	applynumprec(print, spec, ft_nbrlenbase(p, 16));
	if (spec->prec || p)
		uitoabase(p, "0123456789abcdef", print, ft_nbrlenbase(p, 16));
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}
