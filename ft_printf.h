/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:24:47 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/09 18:09:12 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include "../Libft/includes/libft.h"
# include <stdarg.h>

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
int				check_type(const char format);
int				check_minimal_large(const char format, t_struct *form);
int				check_precision(const char format, t_struct *form);
int				check_block(char *block, t_struct *form);
int				set_format(const char *format, va_list va);
int				set_block(const char *format, va_list va);
int				display_block(t_struct *form, va_list va, int i);
int				display_block_2(t_struct *form, va_list va, int i);

void			ft_putwchar(wchar_t c);
void			check_display_block_s(t_struct *form, va_list va);
void			check_display_block_c(t_struct *form, va_list va);
void			check_display_block_d(t_struct *form, va_list va);
void			check_size_modifier(const char *format, t_struct *form);
void			init_struct(t_struct *form);

char			*ui_to_bits(unsigned int u);
char			**uni_mask(char *bits);

#endif
