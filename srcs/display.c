/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/11 14:35:44 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	display_padding(char c, size_t len, size_t min_width)
{
	size_t	i;

	i = 0;
	while (i < (min_width - len))
	{
		ft_putchar(c);
		i++;
	}
}
void		display(t_data *data, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (data->flag->minus)
	{
		ft_putstr(str);
		if (data->min_width > len)
			display_padding(' ', len, data->min_width);
	}
	else
	{
		if (data->min_width > len)
		{
			if (data->flag->zero && data->opt != 'o')
				display_padding('0', len, data->min_width);
			else
				display_padding(' ', len, data->min_width);
		}
		ft_putstr(str);
	}
	if (data->min_width > len)
		COUNT_CHAR(data->min_width);
	else
		COUNT_CHAR(len);
}
