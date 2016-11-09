/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 21:16:43 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 14:31:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	applyprecbin(t_spec *spec, t_print *print, int len)
{
	int		i;
	int		c;

	if (spec->prec > 0)
	{
		c = 0;
		i = 4 * spec->prec - len;
		while (i-- > 0)
		{
			if (!(c % 4) && c)
				addto(' ', print);
			addto('0', print);
			++c;
		}
		if (c)
			addto(' ', print);
	}
}

static void	applyparam(t_spec *spec, t_print *print, int h)
{
	int	i;

	i = (spec->flags & E_SHARP) ? 1 : 0;
	if (!(spec->flags & E_DASH))
		applymfw(print, spec,
			spec->mfw - (h + (i * (h / 4)) - 1));
	applyprecbin(spec, print, h);
}

void		conv_b(t_spec *spec, t_print *print)
{
	uintmax_t	p;
	uintmax_t	tmp;
	size_t		len;
	size_t		i;
	size_t		tmplen;

	p = urecupparam(spec->hljz, print->ap);
	len = ft_bitlen(p);
	tmplen = (4 - (len % 4));
	i = tmplen - 1;
	applyparam(spec, print, (int)(len + tmplen));
	while (tmplen--)
		addto('0', print);
	while (len-- && ++i)
	{
		tmp = p;
		tmplen = len;
		while (tmplen--)
			tmp /= 2;
		if (((spec->flags & E_SHARP) || spec->prec > -1) && !(i % 4))
			addto(' ', print);
		addto(tmp % 2 + '0', print);
	}
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}
