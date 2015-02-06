/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 20:35:10 by ochase            #+#    #+#             */
/*   Updated: 2015/02/06 20:35:23 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	get_integer(t_data *data)
{
	char	*number;
	size_t	i;
	size_t	c;
	size_t	ret;

	i = 0;
	c = 0;
	while (ft_isdigit(data->format[i]))
		i++;
	number = ft_memalloc(i);
	while (c < i && data->format)
	{
		number[c] = *data->format;
		c++;
		data->format++;
	}
	ret = ft_atoi(number);
	free(number);
	return (ret);
}
