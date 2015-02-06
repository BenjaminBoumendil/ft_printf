/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 18:01:01 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parse_flags(t_data *data)
{
	size_t			c;
	BOOL			found;
	const t_token	flags[] = {
	{"#", ft_sharp},
	{"0", ft_zero},
	{"-", ft_minus},
	{"+", ft_plus}};
	while (data->format)
	{
		c = 0;
		found = false;
		while (c < sizeof(flags) / sizeof(t_token))
		{
			if (ft_strchr(flags[c].str, *data->format))
			{
				found = true;
				flags[c].f(data);
				break ;
			}
			c++;
		}
		if (!found)
			break ;
		data->format++;
	}
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
