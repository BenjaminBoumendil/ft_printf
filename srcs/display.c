/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/20 19:21:27 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			display(t_data *data, char *str)
{
	char	*new_str;
	bool	is_null;
	size_t	len;

	is_null = !*str ? true : false;
	new_str = ft_strdup(str);
	display_precision(data, &new_str);
	display_plus(data, &new_str);
	display_space(data, &new_str);
	if (!*new_str && data->precision_called && ft_strchr("sS", data->opt)
		&& data->opt)
		len = ft_strlen(new_str);
	else
		len = !ft_strlen(new_str) ? 1 : ft_strlen(new_str);
	handle_padding(data, &new_str, len);
	ft_putstr(new_str);
	if (is_null == true)
		display_null(data, '\0');
	COUNT_CHAR(ft_strlen(new_str));
	free(new_str);
}
