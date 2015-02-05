/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 23:50:17 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			init_parse(t_data *data)
{
	data->format++;
	parse_flags(data);
	parse_width(data);
	parse_precision(data);
	parse_modifier(data);
	parse_token(data);
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
