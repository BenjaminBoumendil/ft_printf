/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:47:51 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 16:47:02 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		index;
	int		index2;

	index = 0;
	if (s)
	{
		index2 = ft_strlen(s);
		while (index != index2)
		{
			s[index] = '\0';
			++index;
		}
	}
}
