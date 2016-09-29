/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:06:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:41:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_p(t_printf_spec *spec, t_print *print)
{
	int			j;
	uintmax_t	p;

	spec->hljz = E_L;
	p = urecupparam(spec->hljz, print->ap);
	j = !(spec->prec || p) ? 0
		: (ft_max(spec->prec, ft_nbrlenbase(p, 16) + 2));
	(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw - j) : 0;
	addto('0', print);
	addto('x', print);
	applynumprec(print, spec, ft_nbrlenbase(p, 16));
	!(spec->prec || p) ? 0
		: uitoabase(p, "0123456789abcdef", print, ft_nbrlenbase(p, 16));
	(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw) : 0;
}
