/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:18 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 14:31:36 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			free_data(t_data *data)
{
	free(data->flag);
	free(data->modifier);
}

static t_flag		*init_flag(void)
{
	t_flag		*flag;

	flag = ft_memalloc(sizeof(t_flag));
	return (flag);
}

static t_modifier	*init_modifier(void)
{
	t_modifier	*modifier;

	modifier = ft_memalloc(sizeof(t_modifier));
	return (modifier);
}

static void			init_data(t_data *data, const char *format, va_list *va)
{
	ft_bzero(data, sizeof(t_data));
	data->format = format;
	data->va = va;
	data->flag = init_flag();
	data->modifier = init_modifier();
}

int					ft_printf(const char *restrict_format, ...)
{
	va_list		va;
	t_data		data;

	va_start(va, restrict_format);
	init_data(&data, restrict_format, &va);
	read_format(&data);
	free_data(&data);
	va_end(va);
	return (data.char_print);
}
