/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 19:59:13 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parse_flags(t_data *data)
{
	size_t			c;
	BOOL			found;
	const t_flags	flags[] = {
	{'#', ft_sharp},
	{'0', ft_zero},
	{'-', ft_minus},
	{'+', ft_plus}};
	while (data->format)
	{
		c = 0;
		found = false;
		while (c < sizeof(flags) / sizeof(t_flags))
		{
			if (flags[c].c == *data->format)
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
	return (0);
}

int		parse_width(t_data *data)
{
	char	*width;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (ft_isdigit(data->format[i]))
		i++;
	width = ft_memalloc(i);
	while (c < i && data->format)
	{
		width[c] = *data->format;
		c++;
		data->format++;
	}
	data->min_width = ft_atoi(width);
	free(width);
	return (0);
}

int		parse_precision(t_data *data)
{
	(void)data;
	return (0);
}

int		parse_modifier(t_data *data)
{
	(void)data;
	return (0);
}

int		parse_token(t_data *data)
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
	return (0);
}
