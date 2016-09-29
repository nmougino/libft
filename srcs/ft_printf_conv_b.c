/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 21:16:43 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 02:29:23 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	applyprecbin(t_printf_spec *spec, t_print *print, int len)
{
	int	i;
	int	c;

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

static void	applyparam(t_printf_spec *spec, t_print *print, int h)
{
	int	i;

	i = (spec->flags & E_SHARP) ? 1 : 0;
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - (h + (i * (h / 4)) - 1));
	if (spec->prec > 0)
		applyprecbin(spec, print, h);

}

void		conv_b(t_printf_spec *spec, t_print *print)
{
	uintmax_t	p;
	uintmax_t	tmp;
	int			len;
	int			i;
	int			tmplen;

	p = urecupparam(spec->hljz, print->ap);
	len = ft_bitlen(p);
	tmplen = (4 - (len % 4));
	applyparam(spec, print, len + tmplen);
	i = tmplen - 1;
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
