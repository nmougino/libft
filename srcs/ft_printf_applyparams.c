/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_applyparams.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:10:04 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 03:00:26 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	applysharp(t_print *print, t_printf_spec *spec)
{
	if (spec->flags & (1 << 4))
	{
		if (spec->conv == 'o')
			addto('0', print);
		else if (ft_strchr("xX", spec->conv))
		{
			addto('0', print);
			addto(spec->conv, print);
		}
	}
}

void	applyplusspace(t_print *print, t_printf_spec *spec, int s)
{
	if (!s)
		addto('-', print);
	else if (spec->flags & 1)
		addto('+', print);
	else if (spec->flags & (1 << 1))
		addto(' ', print);
	else
		--spec->mfw;
}

void	applymfw(t_print *print, t_printf_spec *spec, int mfw)
{
	while (mfw-- > 0)
		addto(spec->flags & (1 << 3) ? '0' : ' ', print);
}

void	applynumprec(t_print *print, t_printf_spec *spec, size_t len)
{
	while (((size_t)spec->prec - len) > 0)
	{
		addto('0', print);
		spec->prec--;
	}
}
