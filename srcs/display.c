/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/09 13:41:37 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	display_padding(char *str, char c, size_t len, size_t min_width)
{
	size_t	i;

	i = 0;
	while (i < (len - min_width))
	{
		ft_putchar(c);
		i++;
	}
}
void		display(t_data *data, char *str)
{
	size_t	c;
	size_t	len;

	c = 0;
	len = ft_strlen(str);
	if (data->flag->minus)
	{
		ft_putstr(str);
		if (data->min_width < len)
			display_padding(str, ' ', len, data->min_width);
	}
	else
	{
		if (data->min_width < len)
		{
			if (data->flag->zero)
				display_padding(str, '0', len, data->min_width);
			else
				display_padding(str, ' ', len, data->min_width);
		}
		ft_putstr(str);
	}
}
