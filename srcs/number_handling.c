/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 17:17:09 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 20:08:44 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	neg_numbertoken_zeroflag(t_data *data, char **str)
{
	ft_putchar(*str[0]);
	COUNT_CHAR(1);
	(*str)++;
}
