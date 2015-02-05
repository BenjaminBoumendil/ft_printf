/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 23:50:38 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parse_token(t_data *data)
{
	size_t			c;
	const t_token	token[] = {
	{"s", ft_s},
	{"d", ft_d},
	{"c", ft_c}};
	c = 0;
	while (c < sizeof(token) / sizeof(t_token))
	{
		if (!ft_strncmp(token[c].str, data->format, ft_strlen(token[c].str)))
		{
			data->format += ft_strlen(token[c].str);
			token[c].f(data);
		}
		c++;
	}
}

void		parse_flags(t_data *data)
{
	(void)data;
	return ;
}

void		parse_width(t_data *data)
{
	(void)data;
	return ;
}

void		parse_precision(t_data *data)
{
	(void)data;
	return ;
}

void		parse_modifier(t_data *data)
{
	(void)data;
	return ;
}
