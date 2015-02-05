/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:18 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 19:15:24 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		init_data(t_data *data, const char *format, va_list *va)
{
	data->char_print = 0;
	data->format = format;
	data->va = va;
}

int				ft_printf(const char *restrict_format, ...)
{
	va_list		va;
	t_data		data;

	va_start(va, restrict_format);
	init_data(&data, restrict_format, &va);
	read_format(&data);
	va_end(va);
	return (data.char_print);
}
