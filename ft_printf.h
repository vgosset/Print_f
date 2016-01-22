/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:24:47 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/22 20:57:06 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	char		*block;
	int			hash;
	int			minus;
	int			positive;
	int			zero;
	int			space;
	int			minimal_large;
	int			prec;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	char		type;
}				t_struct;

int				ft_printf(const char *format, ...);
int				check_format(const char *format);
int				check_options(const char format, t_struct *form);
void			check_minimal_large(const char format, t_struct *form);
void			check_precision(const char format, t_struct *form);
void			check_size_modifier(const char *format, t_struct *form);

void			init_struct(t_struct *form);

#endif
