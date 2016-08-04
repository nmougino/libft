/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 17:42:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/06/20 17:42:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_mod(t_spec *spec, t_print *print)
{
	(!(spec->flags & E_DASH)) ? applymfw(print, spec, spec->mfw - 1) : 0;
	addto('%', print);
	(spec->flags & E_DASH) ? applymfw(print, spec, spec->mfw) : 0;
}
