/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:42:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 11:49:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_mod(t_spec *spec, t_print *print)
{
	if (!(spec->flags & E_DASH))
		applymfw(print, spec, spec->mfw - 1);
	addto('%', print);
	if (spec->flags & E_DASH)
		applymfw(print, spec, spec->mfw);
}
