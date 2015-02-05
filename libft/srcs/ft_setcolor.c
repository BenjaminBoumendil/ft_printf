/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:20:36 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:42:56 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setcolor(unsigned char color)
{
	char	*color_str;

	color_str = ft_itoa(color);
	ft_putstr("\033[38;5;");
	ft_putstr(color_str);
	ft_putchar('m');
	free(color_str);
}
