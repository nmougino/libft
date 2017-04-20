/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:15:38 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 13:39:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_intmax	recupparam(int type, va_list ap)
{
	if (type == E_INT)
		return ((t_intmax)va_arg(ap, int));
	if (type == E_CHAR)
		return ((t_intmax)(char)va_arg(ap, int));
	if (type == E_SHORT)
		return ((t_intmax)(short)va_arg(ap, int));
	if (type == E_LONG)
		return ((t_intmax)va_arg(ap, long));
	if (type == E_LLONG)
		return ((t_intmax)va_arg(ap, long long));
	if (type == E_SIZE_T)
		return ((t_intmax)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, t_intmax));
	return (0);
}

t_uintmax	urecupparam(int type, va_list ap)
{
	if (type == E_INT)
		return ((t_uintmax)va_arg(ap, unsigned int));
	if (type == E_CHAR)
		return ((t_uintmax)(unsigned char)va_arg(ap, unsigned int));
	if (type == E_SHORT)
		return ((t_uintmax)(unsigned short)va_arg(ap, unsigned int));
	if (type == E_LONG)
		return ((t_uintmax)va_arg(ap, unsigned long));
	if (type == E_LLONG)
		return ((t_uintmax)va_arg(ap, unsigned long long));
	if (type == E_SIZE_T)
		return ((t_uintmax)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, t_uintmax));
	return (0);
}
