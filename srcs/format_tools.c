/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/09 21:00:28 by bboumend         ###   ########.fr       */
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
	char	*str;
	str = va_arg(*data->va, char *);
	if (str)
	{
		COUNT_CHAR(ft_strlen(str));
		ft_putstr(str);
	}
	else
	{
		COUNT_CHAR(6);
		ft_putstr("(null)");
	}
}

void			opt_d(t_data *data)
{
	char	*str;

	str = ft_itoa(va_arg(*data->va, int));
	display(data, str);
	free(str);
}

void			opt_D(t_data *data)
{
	// char		*str;
	long int	i;

	COUNT_CHAR(1);
	i = va_arg(*data->va, long int);
	ft_putnbr(i);
	// str = ft_itoa(i);
	// ft_putstr(str);
}

void			opt_c(t_data *data)
{
	char	*str;

	str = ft_itoa(va_arg(*data->va, int));
	display(data, str);
	free(str);
}
