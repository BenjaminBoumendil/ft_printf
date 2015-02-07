/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:14 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/07 18:13:22 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdarg.h"
# include "../libft/includes/libft.h"

/*
** Defines
*/
# define PRINT_CHAR(v) data->char_print += v
# define BOOL t_bool

typedef enum	e_bool
{
	false,
	true
}				t_bool;

/*
** Flags
*/
typedef struct	s_flag
{
	BOOL		plus;
	BOOL		minus;
	BOOL		sharp;
	BOOL		zero;
	BOOL		space;
}				t_flag;

typedef struct	s_modifier
{
	BOOL		hh;
	BOOL		h;
	BOOL		ll;
	BOOL		l;
	BOOL		j;
	BOOL		z;
}				t_modifier;

/*
** Printf
*/
typedef struct	s_data
{
	int			char_print;
	const char	*format;
	va_list		*va;
	t_flag		*flag;
	t_modifier	*modifier;
	size_t		min_width;
	size_t		precision;
}				t_data;

int				ft_printf(const char *restrict_format, ...);

/*
** Format
*/
typedef struct	s_token
{
	char		*str;
	void		(*f)(t_data *data);
}				t_token;

void			read_format(t_data *data);

/*
** Format tools
*/
void			ft_s(t_data *data);
void			ft_d(t_data *data);
void			ft_c(t_data *data);

/*
** Parser
*/
int				parse_flags(t_data *data);
int				parse_width(t_data *data);
int				parse_precision(t_data *data);
int				parse_modifier(t_data *data);
int				parse_token(t_data *data);

/*
** Parser tools
*/
size_t			get_integer(t_data *data);

/*
** Parser flags
*/
typedef struct	s_flags
{
	char		c;
	void		(*f)(t_data *data);
}				t_flags;

/*
** Flags tools
*/
void			ft_sharp(t_data *data);
void			ft_zero(t_data *data);
void			ft_minus(t_data *data);
void			ft_plus(t_data *data);

/*
** Modifier tools
*/

void			ft_hh(t_data *data);
void			ft_h(t_data *data);
void			ft_ll(t_data *data);
void			ft_l(t_data *data);
void			ft_j(t_data *data);
void			ft_z(t_data *data);

#endif
