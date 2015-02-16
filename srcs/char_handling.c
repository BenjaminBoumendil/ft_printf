/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 22:08:22 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 14:55:33 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	handle_optc_padding(char c, size_t min_width)
{
	while ((min_width - 1) > 0)
	{
		ft_putchar(c);
		min_width--;
	}
}
