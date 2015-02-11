/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_pexXcC.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:23:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/10 23:21:50 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_pe(t_data *data)
{
	COUNT_CHAR(1);
	ft_putchar('%');
	ft_putchar(*data->format);
	data->format++;
}

void		opt_p(t_data *data)
{
	void	*p;
	char	*str;
	int		c;

	p = va_arg(*data->va, void*);
	c = ft_atoi_base(p, 16);
	str = ft_itoa(c);
	display(data, str);
}
#include <stdio.h>
void		opt_e(t_data *data)
{
	double	d;

	d = va_arg(*data->va, double);
	printf("%e", d);
}
