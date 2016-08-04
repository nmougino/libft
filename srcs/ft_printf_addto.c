/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 19:05:45 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/04 17:31:53 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	addto(char c, t_print *print)
{
	if (print->pos == PRINTF_BUFF_SIZE)
	{
		write(print->fd, print->buf, PRINTF_BUFF_SIZE);
		(print->pos) = 0;
	}
	print->buf[print->pos] = c;
	++(print->pos);
	++(print->ans);
	--(print->spec->mfw);
}
