/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/23 13:44:41 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const t_token	g_token[] = {
	{ 's', opt_s }, { 'S', opt_up_s }, { 'd', opt_d }, { 'D', opt_up_d },
	{ 'c', opt_c }, { 'i', opt_d }, { 'o', opt_o }, { 'O', opt_up_o },
	{ '%', opt_per }, { 'u', opt_u }, { 'p', opt_p }, { 'U', opt_up_u },
	{ 'C', opt_up_c }, {'x', opt_x }, {'X', opt_up_x }};

void		parse_flags(t_data *data)
{
	size_t			c;
	const t_flags	flags[] =

	{                                                         \
	{ "#", &data->flag->sharp }, { "0", &data->flag->zero },  \
	{ "-", &data->flag->minus }, { "+", &data->flag->plus },  \
	{ " ", &data->flag->space }};
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
		if (c == (sizeof(flags) / sizeof(t_flags)))
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
		data->precision_called = true;
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

	while (*data->format)
	{
		c = 0;
		while (c < (sizeof(g_token) / sizeof(t_token)))
		{
			if (g_token[c].c == *data->format)
			{
				data->format++;
				data->opt = g_token[c].c;
				g_token[c].f(data);
				return ;
			}
			c++;
		}
		if (c == (sizeof(g_token) / sizeof(t_token)))
		{
			if (data->min_width > 0)
				handle_padding_with_no_option(data);
			break ;
		}
	}
}
