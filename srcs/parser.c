/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/07 23:12:24 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parse_flags(t_data *data)
{
	size_t			c;
	const t_flags	flags[] =

	{                  \
	{ '#', ft_sharp }, \
	{ '0', ft_zero },  \
	{ '-', ft_minus }, \
	{ '+', ft_plus }};
	while (data->format)
	{
		c = 0;
		while (c < (sizeof(flags) / sizeof(t_flags)))
		{
			if (flags[c].c == *data->format)
			{
				flags[c].f(data);
				break ;
			}
			c++;
		}
		if (c >= (sizeof(flags) / sizeof(t_flags)))
			break ;
		data->format++;
	}
	return (0);
}

int		parse_width(t_data *data)
{
	data->min_width = get_integer(data);
	return (0);
}

int		parse_precision(t_data *data)
{
	if (*data->format == '.')
	{
		data->format++;
		data->precision = get_integer(data);
	}
	return (0);
}

int		parse_modifier(t_data *data)
{
	size_t			c;
	const t_token	mod[] =

	{                \
	{ "hh", ft_hh }, \
	{ "h", ft_h },   \
	{ "ll", ft_ll }, \
	{ "l", ft_l },   \
	{ "j", ft_j },   \
	{ "z", ft_z }};
	while (data->format)
	{
		c = 0;
		while (c < (sizeof(mod) / sizeof(t_token)))
		{
			if (!ft_strncmp(mod[c].str, data->format, ft_strlen(mod[c].str)))
			{
				data->format += ft_strlen(mod[c].str);
				mod[c].f(data);
				break ;
			}
			c++;
		}
		if (c == (sizeof(mod) / sizeof(t_token)))
			break ;
	}
	return (0);
}

int		parse_token(t_data *data)
{
	size_t			c;
	const t_token	token[] =

	{              \
	{ "s", ft_s }, \
	{ "d", ft_d }, \
	{ "c", ft_c }};
	c = 0;
	while (c < (sizeof(token) / sizeof(t_token)))
	{
		if (!ft_strncmp(token[c].str, data->format, ft_strlen(token[c].str)))
		{
			data->format += ft_strlen(token[c].str);
			token[c].f(data);
			break ;
		}
		c++;
	}
	return (0);
}
