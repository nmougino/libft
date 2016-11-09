/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:09:25 by nmougino          #+#    #+#             */
/*   Updated: 2016/11/06 13:36:53 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	initprint(t_print *print, t_spec *spec)
{
	(print->convftab[0]) = (void*)(&conv_s);
	(print->convftab[1]) = (void*)(&conv_ls);
	(print->convftab[2]) = (void*)(&conv_p);
	(print->convftab[3]) = (void*)(&conv_d);
	(print->convftab[4]) = (void*)(&conv_ld);
	(print->convftab[5]) = (void*)(&conv_i);
	(print->convftab[6]) = (void*)(&conv_o);
	(print->convftab[7]) = (void*)(&conv_lo);
	(print->convftab[8]) = (void*)(&conv_u);
	(print->convftab[9]) = (void*)(&conv_lu);
	(print->convftab[10]) = (void*)(&conv_x);
	(print->convftab[11]) = (void*)(&conv_bx);
	(print->convftab[12]) = (void*)(&conv_c);
	(print->convftab[13]) = (void*)(&conv_lc);
	(print->convftab[14]) = (void*)(&conv_b);
	(print->convftab[15]) = (void*)(&conv_mod);
	print->pos = 0;
	print->ans = 0;
	spec->hljz = 0;
	spec->flags = 0;
	spec->mfw = 0;
	print->spec = spec;
	ft_bzero(print->buf, BUF_SIZE);
}

static int	printerror(t_print *print)
{
	write(print->fd, print->buf, print->pos);
	va_end(print->ap);
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	int				i;
	int				tmp;
	t_print			print;
	t_spec			spec;

	i = 0;
	va_start(print.ap, format);
	initprint(&print, &spec);
	print.fd = 1;
	while (format[i])
	{
		if (format[i] != '%')
			addto(format[i], &print);
		else if ((tmp = conv(&spec, &print, format + i + 1)) == -1)
			return (printerror(&print));
		else
			i += tmp;
		++i;
	}
	write(1, print.buf, print.pos);
	va_end(print.ap);
	return (print.ans);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	int				i;
	int				tmp;
	t_print			print;
	t_spec			spec;

	i = 0;
	va_start(print.ap, format);
	initprint(&print, &spec);
	print.fd = fd;
	while (format[i])
	{
		if (format[i] != '%')
			addto(format[i], &print);
		else if ((tmp = conv(&spec, &print, format + i + 1)) == -1)
			return (printerror(&print));
		else
			i += tmp;
		i++;
	}
	write(fd, print.buf, print.pos);
	va_end(print.ap);
	return (print.ans);
}
