/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 17:31:49 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/06 17:29:15 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/printf.h"

int			main(void)
{
	// ft_putstr("MY PRINTF : \n");
	ft_printf("%+-#0s\n", "test");
	// ft_printf("%s\n%d\n%c\n", "test", 42, 48);

	// ft_putstr("\nREAL PRINTF : \n");
	// printf("TEST\n");
	// printf("%s\n%d\n%c\n", "test", 42, 48);
	// printf("%+#e%d", 42.25, 42);

	return (0);
}
