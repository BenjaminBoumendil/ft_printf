/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 20:51:37 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:44:12 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_foreach(char **tab, t_tabf f, void *data)
{
	size_t	c;

	c = 0;
	while (tab[c])
	{
		f(tab[c], data);
		++c;
	}
}
