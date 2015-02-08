/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/08 22:33:24 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		parse_flags(t_data *data)
{
	size_t			c;
	const t_flags	flags[] =

	{                                                         \
	{ "#", &data->flag->sharp }, { "0", &data->flag->zero },  \
	{ "-", &data->flag->minus }, { "+", &data->flag->plus }};
	while (*data->format)
	{
		c = 0;
		while (c < (sizeof(flags) / sizeof(t_flags)))
		{
			if (*flags[c].str == *data->format)
			{
				*(flags[c].flag) = true;
				break ;
			}
			c++;
		}
		if (c >= (sizeof(flags) / sizeof(t_flags)))
			break ;
		data->format++;
	}
}

void		parse_width(t_data *data)
{
	data->min_width = get_integer(data);
}

void		parse_precision(t_data *data)
{
	if (*data->format == '.')
	{
		data->format++;
		data->precision = get_integer(data);
	}
}

void		parse_modifier(t_data *data)
{
	size_t			c;
	const t_flags	mod[] =

	{                                                             \
	{ "hh", &data->modifier->hh }, { "h", &data->modifier->h },   \
	{ "ll", &data->modifier->ll }, { "l", &data->modifier->l },   \
	{ "j", &data->modifier->j }, { "z", &data->modifier->z }};
	while (*data->format)
	{
		c = 0;
		while (c < (sizeof(mod) / sizeof(t_flags)))
		{
			if (!ft_strncmp(mod[c].str, data->format, ft_strlen(mod[c].str)))
			{
				data->format += ft_strlen(mod[c].str);
				*(mod[c].flag) = true;
				break ;
			}
			c++;
		}
		if (c == (sizeof(mod) / sizeof(t_flags)))
			break ;
	}
}

void		parse_token(t_data *data)
{
	size_t			c;
	const t_token	token[] =

	{              \
	{ 's', opt_s }, { 'd', opt_d }, { 'c', opt_c }};
	while (*data->format)
	{
		c = 0;
		while (c < (sizeof(token) / sizeof(t_token)))
		{
			if (token[c].c == *data->format)
			{
				data->format++;
				token[c].f(data);
				break ;
			}
			c++;
		}
		if (c == (sizeof(token) / sizeof(t_token)))
			data->format++;
	}
}
