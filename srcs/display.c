/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/14 17:35:09 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*display_padding(char *str, char c, size_t len, size_t min_width)
{
	size_t	i;

	i = 0;
	while (i < (min_width - len))
	{
		ft_putchar(c);
		i++;
	}
	return (str);
}

static void	display_plus(t_data *data, char *str)
{
	if (data->flag->plus && str[0] != '-')
	{
		ft_putchar('+');
		COUNT_CHAR(1);
	}
}

static void	display_minus(t_data *data, char *str, size_t len)
{
	ft_putstr(str);
	if (data->min_width > len)
		str = display_padding(str, ' ', len, data->min_width);
}

void		display(t_data *data, char *str)
{
	size_t	len;

	len = ft_strlen(str);
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
				str = display_padding(str, '0', len, data->min_width);
			else
				str = display_padding(str, ' ', len, data->min_width);
		}
		ft_putstr(str);
	}
	if (data->min_width > len)
		COUNT_CHAR(data->min_width);
	else
		COUNT_CHAR(len);
}
