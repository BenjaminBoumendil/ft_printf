/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scases_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:35:54 by ochase            #+#    #+#             */
/*   Updated: 2015/02/12 19:20:06 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	handle_neg_numbers(t_data *data, char **str)
{
	if (data->flag->zero)
		neg_numbertoken_zeroflag(str);
}

static int	handle_numbers(t_data *data, char **str)
{
	if (*str[0] == '-')
		handle_neg_numbers(data, str);
	if (ft_strchr("oO", data->opt))
		data->flag->plus = false;
	return (0);
}

static int	handle_chars(t_data *data, char **str)
{
	if (!**str && !data->flag->zero && !ft_strchr("s", data->opt))
	{
		COUNT_CHAR(1);
		return (1);
	}
	data->flag->plus = false;
	return (0);
}

static int	handle_other(t_data *data, char **str)
{
	(void)data;
	(void)str;
	return (0);
}

int			handle_special_cases(t_data *data, char **str)
{
	size_t			c;
	const t_handle	token_tab[] =

	{                                                         \
	{ "dDoOuUxX", handle_numbers }, { "sScC", handle_chars }, \
	{ "%p", handle_other }};
	c = 0;
	while (c < (sizeof(token_tab) / sizeof(t_handle)))
	{
		if (ft_strchr(token_tab[c].tokens, data->opt))
			return (token_tab[c].f(data, str));
		c++;
	}
	return (0);
}
