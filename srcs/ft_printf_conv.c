/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 19:00:03 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/29 01:42:52 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	setspec(t_print *print, t_printf_spec *spec, const char *str)
{
	int		i;
	int		ans;

	ans = 0;
	ans += setflag(spec, str);
	ans += setmfwi(print, spec, str + ans);
	ans += setprec(spec, str + ans);
	ans += setmodi(spec, str + ans);
	if ((i = setconv(spec, str + ans)) == -1)
		return (-1);
	ans += i;
	return (ans);
}

int			conv(t_printf_spec *spec, t_print *print, const char *format)
{
	void	(*convf)(t_printf_spec*, t_print*);
	int		tmp;

	if (format[0] == '%')
	{
		addto('%', print);
		return (1);
	}
	if ((tmp = setspec(print, spec, format)) == -1)
		return (-1);
	convf = print->convftab[ft_strnloc(spec->conv, "sSpdDioOuUxXcCb%", 16)];
	convf(spec, print);
	return (tmp);
}
