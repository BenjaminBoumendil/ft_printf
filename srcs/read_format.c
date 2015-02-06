/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 20:21:11 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define F0 int		(*f[])(t_data *data) = {
#define F1 parse_flags,
#define F2 parse_width,
#define F3 parse_precision,
#define F4 parse_modifier,
#define F5 parse_token};
#define F F0 F1 F2 F3 F4 F5

static void			init_parse(t_data *data)
{
	size_t	i;

	F;
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
