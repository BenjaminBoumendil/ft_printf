/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 17:33:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_s(t_data *data)
{
	char	*str;

	str = va_arg(*data->va, char *);
	PRINT_CHAR(ft_strlen(str));
	ft_putstr(str);
}

void			ft_d(t_data *data)
{
	PRINT_CHAR(1);
	ft_putnbr(va_arg(*data->va, int));
}

void			ft_c(t_data *data)
{
	PRINT_CHAR(1);
	ft_putchar(va_arg(*data->va, int));
}