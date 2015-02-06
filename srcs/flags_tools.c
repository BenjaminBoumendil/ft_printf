/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 17:20:00 by ochase            #+#    #+#             */
/*   Updated: 2015/02/06 20:00:28 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_sharp(t_data *data)
{
	data->flag->sharp = true;
}

void		ft_zero(t_data *data)
{
	data->flag->zero = true;
}

void		ft_minus(t_data *data)
{
	data->flag->minus = true;
}

void		ft_plus(t_data *data)
{
	data->flag->plus = true;
}
