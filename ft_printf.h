/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:24:47 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/02 13:31:29 by jle-quer         ###   ########.fr       */
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
	int			larg;
	int			prec;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	char		type;
}				t_struct;

int				g_ret;

int				ft_printf(const char *format, ...);
int				check_format(const char *format);
int				check_options(const char format, t_struct *form);
int				check_type(const char format);
int				check_minimal_large(const char format, t_struct *form);
int				check_precision(const char format, t_struct *form);
int				check_block(char *block, t_struct *form);
int				set_block(const char *format, va_list va);
int				display_block(t_struct *form, va_list va, int i);
int				ft_isspace(int c);
int				ft_count(long n);
int				ft_count_base(unsigned long n, int base);
int				ft_count_wchar(unsigned int wchar);

long			ft_power(long nb, int i);
long long		check_display_block_d(t_struct *form, va_list va);
uintmax_t		check_display_block_o(t_struct *form, va_list va);
uintmax_t		check_display_block_x(t_struct *form, va_list va);
uintmax_t		check_display_block_u(t_struct *form, va_list va);
unsigned long	check_display_block_p(va_list va);

void			ft_putint(int c);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putstr(char const *s);
void			ft_putwstr(wchar_t *str);
void			set_format(const char *format, va_list va);
void			check_size_modifier(const char *format, t_struct *form);
void			init_struct(t_struct *form);
void			print_oct(char *mask);
void			ft_bzero(void *s, size_t n);
void			checkflags(t_struct *form, char a, char b);
void			set_c(t_struct *form, va_list va);
void			set_s(t_struct *form, va_list va);
void			set_wchar_s(t_struct *form, va_list va);

char			*ft_itoa(int n);
char			*ft_itoa_base(long long nbr, int base);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
char			*ui_to_bits(unsigned int u);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*place(int n, char c);
char			*place_s(int n, char c);
char			*set_upper(char *str);
char			*set_d(t_struct *form, va_list va);
char			*set_octal(t_struct *form, va_list va);
char			*set_hex(t_struct *form, va_list va);
char			*set_u(t_struct *form, va_list va);
char			*set_p(t_struct *form, va_list va);

char			**uni_mask(char *bits);
char			**uni_mask_1(char *bits, char *mask, size_t b_len, int m_len);
char			**ft_strsplit(char const *s, char c);

size_t			ft_words(char const *str, char c);
size_t			ft_strlen(const char *s);

#endif
