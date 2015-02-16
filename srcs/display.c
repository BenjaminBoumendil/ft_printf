/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 18:42:20 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	display_padding(char c, size_t len, t_data *data)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = data->min_width - len;
	if (ft_strchr("d", data->opt) && data->precision > 0)
		count = ((data->min_width - data->precision) > 0 ? data->min_width -
			data->precision : data->precision - data->min_width);
	while (i < count)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

static void		display_plus(t_data *data, char *str)
{
	if (data->flag->plus && str[0] != '-')
	{
		ft_putchar('+');
		COUNT_CHAR(1);
	}
}

static void		display_minus(t_data *data, char *str, size_t len)
{
	char	c;

	c = ' ';
	if (data->flag->zero && ft_strchr("p", data->opt))
		c = '0';
	*str == '\0' ? write(1, str, 1) : ft_putstr(str);
	if (data->min_width > len)
		COUNT_CHAR(display_padding(c, len, data));
}

void			display(t_data *data, char *str)
{
	size_t	len;

	if (!(len = ft_strlen(str)))
		len = 1;
	if (handle_special_cases(data, &str) == 1)
		return ;
	if (data->flag->minus)
		display_minus(data, str, len);
	else
	{
		display_plus(data, str);
		if (data->min_width > len)
		{
			if (data->flag->zero && data->opt != 'o')
				COUNT_CHAR(display_padding('0', len, data));
			else
				COUNT_CHAR(display_padding(' ', len, data));
		}
		if (data->precision > 0)
			handle_precision(data, ft_strlen(str));
		*str == '\0' ? write(1, str, 1) : ft_putstr(str);
	}
	COUNT_CHAR(ft_strlen(str));
}
