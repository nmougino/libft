/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_uni.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:09:48 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:41:23 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	adduni(wchar_t p, int nbbi, t_print *print)
{
	if (nbbi >= 1 && nbbi <= 7)
		addto(p, print);
	else if (nbbi >= 8 && nbbi <= 11)
	{
		addto(((3 << 6) | (p >> 6)), print);
		addto(((1 << 7) | (63 & p)), print);
	}
	else if (nbbi >= 12 && nbbi <= 16)
	{
		addto((7 << 5) | (p >> 12), print);
		addto((1 << 7) | (63 & (p >> 6)), print);
		addto((1 << 7) | (63 & p), print);
	}
	else if (nbbi >= 17 && nbbi <= 21)
	{
		addto((15 << 4) | (p >> 18), print);
		addto((1 << 7) | (63 & (p >> 12)), print);
		addto((1 << 7) | (63 & (p >> 6)), print);
		addto((1 << 7) | (63 & p), print);
	}
}

static int	ft_wstrlen(wchar_t *p)
{
	int		i;

	i = 0;
	while (p[i])
		++i;
	return (i);
}

static int	nboc(int nbbi)
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

void		conv_lc(t_printf_spec *spec, t_print *print)
{
	wchar_t	p;
	int		nbbi;

	p = (wchar_t)urecupparam(spec->hljz, print->ap);
	nbbi = ft_bitlen(p);
	(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw -
		nboc(nbbi)) : 0;
	adduni(p, nbbi, print);
	((spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw) : 0;
}

void		conv_ls(t_printf_spec *spec, t_print *print)
{
	wchar_t	*p;
	int		i;
	int		nbbi;
	int		j;

	i = 0;
	p = (wchar_t*)urecupparam(E_LONG, print->ap);
	if (!p)
		p = L"(null)";
	nbbi = ft_bitlen(p[i]);
	j = (spec->prec <= -1) ? nboc(nbbi) : 0;
	(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw -
		ft_wstrlen(p) - j) : 0;
	while (p[i] && (spec->prec > 0 || spec->prec <= -1))
	{
		nbbi = ft_nbrlenbase(p[i], 2);
		spec->prec -= nboc(nbbi);
		adduni(p[i], nbbi, print);
		i++;
	}
	((spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw) : 0;
}
