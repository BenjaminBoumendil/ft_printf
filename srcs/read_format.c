/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/08 23:35:32 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			init_parse(t_data *data)
{
	data->format++;
	parse_flags(data);
	parse_width(data);
	parse_precision(data);
	parse_modifier(data);
	parse_token(data);
	return (0);
}

void				read_format(t_data *data)
{
	while (*data->format)
	{
		if (*data->format == '%')
		{
			if (init_parse(data))
				return ;
		}
		else
		{
			COUNT_CHAR(1);
			ft_putchar(*data->format);
			data->format++;
		}
	}
}
