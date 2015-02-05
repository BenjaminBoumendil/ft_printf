/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 19:56:44 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/23 19:45:21 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_new_line(const char *remains)
{
	const char *str;

	if (remains)
	{
		str = remains;
		while (*str)
		{
			if (*str == '\n')
				return (str - remains);
			++str;
		}
	}
	return (-1);
}

static void	clear_remains(char **remains, int cur_line)
{
	char	*tmp;
	int		len;

	if (*remains)
	{
		len = ft_strlen(*remains);
		tmp = ft_strsub(*remains, cur_line + 1, len - cur_line);
		free(*remains);
		*remains = tmp;
		if (cur_line == -1)
		{
			free(*remains);
			*remains = 0;
		}
	}
}

int			get_next_line(const int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	static char	*remains = NULL;
	int			cur_line;

	ret = 1;
	while ((cur_line = find_new_line(remains)) < 0 && ret)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		remains = remains ? ft_strjoin(remains, buf) : ft_strdup(buf);
	}
	if (ft_strlen(remains) == 0)
		return (0);
	*line = ft_strsub(remains, 0, ft_strsublen(remains, 0, '\n'));
	clear_remains(&remains, cur_line);
	return (1);
}
