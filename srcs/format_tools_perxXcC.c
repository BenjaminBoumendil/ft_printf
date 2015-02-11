/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_perxXcC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:23:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 17:28:02 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_per(t_data *data)
{
	display(data, va_arg(*data->va, char *));
}

// void		opt_per(t_data *data)
// {
	// COUNT_CHAR(1);
	// ft_putchar('%');
	// ft_putchar(*data->format);
	// data->format++;
// }

void			opt_c(t_data *data)
{
	char	str[2];
	int		c;
	c = va_arg(*data->va, int);
	if (c == 0)
	{
		COUNT_CHAR(1);
		return ;
	}
	str[0] = (char)c;
	str[1] = '\0';
	display(data, str);
}
