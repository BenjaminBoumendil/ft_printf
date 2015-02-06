/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:20:00 by ochase            #+#    #+#             */
/*   Updated: 2015/02/06 17:41:44 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_sharp(t_data *data)
{
	(void)data;
	ft_putstr("sharp ");
}

void		ft_zero(t_data *data)
{
	(void)data;
	ft_putstr("zero " );
}

void		ft_minus(t_data *data)
{
	(void)data;
	ft_putstr("minus ");
}

void		ft_plus(t_data *data)
{
	(void)data;
	ft_putstr("plus ");
}
