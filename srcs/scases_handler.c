/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scases_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:35:54 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 21:59:52 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	handle_neg_numbers(t_data *data, char **str)
{
	if (data->flag->zero)
		neg_numbertoken_zeroflag(data, str);
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
	char	*ret;

	if (!**str && (ret = ft_strchr("scC", data->opt)))
	{
		if (!data->flag->zero && *ret == 's')
			return (1);
		COUNT_CHAR(1);
	}
	data->flag->plus = false;
	return (0);
}

static int	handle_other(t_data *data, char **str)
{
	(void)str;
	if (ft_strchr("p", data->opt) && data->flag->zero)
		data->flag->minus = true;
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
