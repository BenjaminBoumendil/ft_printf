/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 15:20:57 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_o(t_data *data)
{
	char	*str;

	str = ft_itoa_base(va_arg(*data->va, int), B_OCT);
	display(data, str);
	data->char_print = -1;
	free(str);
}

void		opt_per(t_data *data)
{
	display(data, va_arg(*data->va, char *));
}
