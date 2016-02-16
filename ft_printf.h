/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:24:47 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/16 17:29:36 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_F_H
# define FT_PRINT_F_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_struct
{
	char		*block;
	int			hash;
	int			moins;
	int			plus;
	int			zero;
	int			space;
	int			large;
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
int				ft_isspace(int c);
int				ft_count(int n);
int				ft_atoi(const char *str);

long			ft_power(long nb, int i);

void			ft_putint(int c);
void			ft_putnbr(int n);
void			ft_puthex(unsigned long nbr);
void			ft_puthex_X(unsigned long nbr);
void			ft_putoctal(unsigned long nbr);
void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putstr(char const *s);
void			ft_putwstr(wchar_t *str);
void			check_display_block_s(t_struct *form, va_list va);
void			check_display_block_c(t_struct *form, va_list va);
void			check_display_block_d(t_struct *form, va_list va);
void			check_display_block_x(t_struct *form, va_list va);
void			check_display_block_o(t_struct *form, va_list va);
void			check_size_modifier(const char *format, t_struct *form);
void			init_struct(t_struct *form);
void			print_oct(char *mask);
void			ft_bzero(void *s, size_t n);

char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
char			*ui_to_bits(unsigned int u);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);

char			**uni_mask(char *bits);
char			**uni_mask_1(char *bits, char *mask, size_t b_len, int m_len);
char			**ft_strsplit(char const *s, char c);

size_t			ft_words(char const *str, char c);
size_t			ft_strlen(const char *s);

#endif
