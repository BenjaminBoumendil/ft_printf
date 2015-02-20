/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 19:03:39 by ochase            #+#    #+#             */
/*   Updated: 2015/02/20 19:25:32 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*fill_padding_char(char c, size_t min_width, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_memalloc(min_width + 1);
	while (i < (min_width - len))
	{
		new_str[i] = c;
		i++;
	}
	return (new_str);
}

static void		display_padding(t_data *data, char c, size_t len, char **str, int rev)
{
	char	*save;

	if (len < data->min_width)
	{
		save = *str;
		if (!rev && !data->flag->space)
			*str = ft_strjoin(fill_padding_char(c, data->min_width, len), *str);
		else
			*str = ft_strjoin(*str, fill_padding_char(c, data->min_width, len));
		free(save);
	}
}

static void		display_rev_padding(t_data *data, char **str, size_t len)
{
	char	c;

	c = ' ';
	if (!data->flag->minus && ft_strchr("p", data->opt))
		c = '0';
	if (data->min_width > len)
		display_padding(data, c, len, str, 1);
}

void			handle_padding(t_data *data, char **new_str, size_t len)
{
	if (data->flag->minus || (data->opt == 'p' && data->flag->zero))
		display_rev_padding(data, new_str, len);
	else
	{
		if (!data->precision && data->flag->zero && data->opt != 'o')
			display_padding(data, '0', len, new_str, 0);
		else
			display_padding(data, ' ', len, new_str, 0);
	}
	if (ft_strchr(NUMBER_OPT, data->opt) && data->flag->zero)
		check_for_sign(new_str);
}
