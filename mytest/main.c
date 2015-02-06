/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:31:49 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 22:20:03 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/printf.h"

int			main(void)
{
	ft_putstr("MY PRINTF : \n");
	ft_printf("%d", 42);

	ft_putstr("\nREAL PRINTF : \n");
	printf("%d", 42);

	return (0);
}
