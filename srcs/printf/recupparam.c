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

intmax_t	recupparam(int type, va_list ap)
{
	if (type == E_INT)
		return ((intmax_t)va_arg(ap, int));
	if (type == E_CHAR)
		return ((intmax_t)(char)va_arg(ap, int));
	if (type == E_SHORT)
		return ((intmax_t)(short)va_arg(ap, int));
	if (type == E_LONG)
		return ((intmax_t)va_arg(ap, long));
	if (type == E_LLONG)
		return ((intmax_t)va_arg(ap, long long));
	if (type == E_SIZE_T)
		return ((intmax_t)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, intmax_t));
	return (0);
}

uintmax_t	urecupparam(int type, va_list ap)
{
	if (type == E_INT)
		return ((uintmax_t)va_arg(ap, unsigned int));
	if (type == E_CHAR)
		return ((uintmax_t)(unsigned char)va_arg(ap, unsigned int));
	if (type == E_SHORT)
		return ((uintmax_t)(unsigned short)va_arg(ap, unsigned int));
	if (type == E_LONG)
		return ((uintmax_t)va_arg(ap, unsigned long));
	if (type == E_LLONG)
		return ((uintmax_t)va_arg(ap, unsigned long long));
	if (type == E_SIZE_T)
		return ((uintmax_t)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, uintmax_t));
	return (0);
}
