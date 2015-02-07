/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 18:10:13 by ochase            #+#    #+#             */
/*   Updated: 2015/02/07 18:14:33 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_hh(t_data *data)
{
	data->modifier->hh = true;
}

void	ft_h(t_data *data)
{
	data->modifier->h = true;
}

void	ft_ll(t_data *data)
{
	data->modifier->ll = true;
}

void	ft_l(t_data *data)
{
	data->modifier->l = true;
}

void	ft_j(t_data *data)
{
	data->modifier->j = true;
}
