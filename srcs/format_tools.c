/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 15:23:37 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			opt_s(t_data *data)
{
	char	*str;

	str = va_arg(*data->va, char *);
	if (str)
		display(data, str);
	else
		display(data, "(null)");
}

void			opt_S(t_data *data)
{
	va_arg(*data->va, char *);
	COUNT_CHAR(-1);
}

void			opt_d(t_data *data)
{
	char	*str;

	str = ft_itoa(va_arg(*data->va, int));
	display(data, str);
	if (data->opt == 'i')
		data->char_print = -1;
	free(str);
}

void			opt_D(t_data *data)
{
	char		*str;
	long int	i;

	i = va_arg(*data->va, long);
	str = ft_ltoa(i);
	display(data, str);
	free(str);
}

void			opt_c(t_data *data)
{
	char	str[2];


	str[0] = (char)va_arg(*data->va, int);
	str[1] = '\0';
	display(data, str);
	data->char_print = -1;
}
