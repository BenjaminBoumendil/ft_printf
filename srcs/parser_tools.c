/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 20:35:10 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 16:03:27 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	get_integer(t_data *data)
{
	size_t	ret;

	ret = 0;
	while (ft_isdigit(*data->format))
		ret = ret * 10 + *data->format++ - '0';
	return (ret);
}

void	handle_padding_with_no_option(t_data *data)
{
	char	*str;

	str = ft_memalloc(2);
	str = ft_strncpy(str, data->format, 1);
	data->format++;
	display(data, str);
	free(str);
}
