/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:24:25 by ochase            #+#    #+#             */
/*   Updated: 2015/02/11 17:24:34 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	{ 's', opt_s }, { 'S', opt_S }, { 'd', opt_d }, /* { 'D', opt_D }, */
	{ 'c', opt_c }, { 'i', opt_d }, { 'o', opt_o }, { 'O', opt_O },
	{ '%', opt_per }, { 'u', opt_u }, /* { 'p', opt_p } */};
	while (*data->format)
	{
		c = 0;
		while (c < (sizeof(token) / sizeof(t_token)))
		{
			if (token[c].c == *data->format)
			{
				data->format++;
				data->opt = token[c].c;
				token[c].f(data);
				return ;
			}
			c++;
		}
		if (c == (sizeof(token) / sizeof(t_token)))
			break ;
	}
}
