/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:31:49 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 18:01:59 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/printf.h"

int			main(void)
{
	ft_putstr("MY PRINTF : \n");
	ft_printf("TEST\n");
	ft_printf("%s\n%d\n%c\n", "test", 42, 48);
	ft_printf("%s", NULL);

	ft_putstr("\nREAL PRINTF : \n");
	// printf("TEST\n");
	// printf("%s\n%d\n%c\n", "test", 42, 48);
	printf("%s", 0);

	return (0);
}