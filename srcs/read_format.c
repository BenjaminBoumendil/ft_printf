/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 17:51:58 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			init_parse(t_data *data)
{
	size_t			i;
	void (*f[])(t_data *data) =

	{						\
		parse_flags,		\
		parse_width,		\
		parse_precision,	\
		parse_modifier,		\
		parse_token};
	i = 0;
	data->format++;
	while (i < sizeof(f) / sizeof(*f))
	{
		f[i++](data);
	}
}

void				read_format(t_data *data)
{
	while (*data->format)
	{
		if (*data->format == '%')
			init_parse(data);
		else
		{
			PRINT_CHAR(1);
			ft_putchar(*data->format);
			data->format++;
		}
	}
}
