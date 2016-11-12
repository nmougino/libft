/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:09:48 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/12 17:55:19 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		adduni(wchar_t p, size_t nbbi, t_print *print)
{
	if (nbbi >= 1 && nbbi <= 7)
		addto((char)p, print);
	else if (nbbi >= 8 && nbbi <= 11)
	{
		addto((char)((3 << 6) | (p >> 6)), print);
		addto((char)((1 << 7) | (63 & p)), print);
	}
	else if (nbbi >= 12 && nbbi <= 16)
	{
		addto((char)((7 << 5) | (p >> 12)), print);
		addto((char)((1 << 7) | (63 & (p >> 6))), print);
		addto((char)((1 << 7) | (63 & p)), print);
	}
	else if (nbbi >= 17 && nbbi <= 21)
	{
		addto((char)((15 << 4) | (p >> 18)), print);
		addto((char)((1 << 7) | (63 & (p >> 12))), print);
		addto((char)((1 << 7) | (63 & (p >> 6))), print);
		addto((char)((1 << 7) | (63 & p)), print);
	}
}

static int		ft_wstrlen(wchar_t *p)
{
	int	i;

	i = 0;
	while (p[i])
		++i;
	return (i);
}

static int		nboc(size_t nbbi)
{
	if (nbbi >= 1 && nbbi <= 7)
		return (1);
	else if (nbbi >= 8 && nbbi <= 11)
		return (2);
	else if (nbbi >= 12 && nbbi <= 16)
		return (3);
	else if (nbbi >= 17 && nbbi <= 21)
		return (4);
	return (0);
}

void			conv_lc(t_spec *spec, t_print *print)
{
	wchar_t	p;
	size_t	nbbi;

	p = (wchar_t)urecupparam(spec->hljz, print->ap);
	nbbi = ft_bitlen((uintmax_t)p);
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - nboc(nbbi));
	adduni(p, nbbi, print);
	if ((spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw);
}

void			conv_ls(t_spec *spec, t_print *print)
{
	wchar_t	*p;
	int		i;
	size_t	nbbi;
	int		j;

	i = 0;
	p = (wchar_t*)(unsigned long)urecupparam(E_LONG, print->ap);
	if (!p)
		p = L"(null)";
	nbbi = ft_bitlen((uintmax_t)p[i]);
	j = (spec->prec <= -1) ? nboc(nbbi) : 0;
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - ft_wstrlen(p) - j);
	while (p[i] && (spec->prec > 0 || spec->prec <= -1))
	{
		nbbi = ft_nbrlenbasemax((uintmax_t)p[i], 2);
		spec->prec -= nboc(nbbi);
		adduni(p[i], nbbi, print);
		i++;
	}
	if ((spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw);
}
