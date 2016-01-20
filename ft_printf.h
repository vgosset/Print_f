/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:24:47 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/20 16:33:26 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "../Libft/libft.h"
# include <stdarg.h>

typedef struct	s_struct
{
	char		*block;
	int			hash;
	int			minus;
	int			positive;
	int			zero;
	int			space;
	int			large;
	int			prec;
	char		size;
	char		type;
}				t_struct;

int				ft_printf(const char *format, ...);
int				check_format(const char *format);
int				check_block(const char *format, t_struct *form);

void			init_struct(t_struct *form);

#endif
