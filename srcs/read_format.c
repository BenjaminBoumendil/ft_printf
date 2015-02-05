/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 19:33:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t		pars_token(t_data *data)
{
	size_t			c;
	const t_token	token[] = {
	{"%s", ft_s},
	{"%d", ft_d},
	{"%c", ft_c}};

	c = 0;
	while (c < sizeof(token) / sizeof(t_token))
	{
		if (!ft_strncmp(token[c].str, data->format, ft_strlen(token[c].str)))
		{
			token[c].f(data);
		}
		c++;
	}
	return (2);
}

void				read_format(t_data *data)
{
	while (*data->format)
	{
		if (*data->format == '%')
			data->format += pars_token(data);
		else
		{
			PRINT_CHAR(1);
			ft_putchar(*data->format);
			data->format++;
		}
	}
}
