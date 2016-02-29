/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:21:34 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/25 19:51:00 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_d_0(char *str, int nbr0)
{
	char	*str0;
	char	*new;
	int		i;

	str0 = ft_strnew(nbr0 + 1);
	i = 0;
	while (i < nbr0)
	{
		str0[i] = '0';
		i++;
	}
	str0[i] = '\0';
	new = ft_strjoin(str0, str);
	return (new);
}

static char	*set_d_larg(t_struct *strct, char *str)
{
	char *larg;

	if (strct->zero == 1 && strct->prec == -1)
		larg = place(strct->larg - ft_strlen(str), '0');
	else
		larg = place(strct->larg - ft_strlen(str), ' ');
	return (larg);
}

//static char	*set_d_plus_space(char *str, char c)
//{
//	char *new;

//	new = ft_strnew(1);
//	new[0] = c;
//	str = ft_strjoin(new, str);
//	return (str);
//}

static char	*set_moins_d(t_struct *strct, char *str, char *larg)
{
	char	*new;

	if (strct->moins == 0)
		new = ft_strjoin(larg, str);
	else
		new = ft_strjoin(str, larg);
	return (new);
}

static char	*set_hash(uintmax_t n)
{
	char	*new;

	new = ft_strjoin("0", ft_itoa_base(n, 8));
	return (new);
}

char	*set_octal(t_struct *strct, va_list va)
{
	char		*larg;
	char		*str;
	uintmax_t	n;

	checkflags(strct, '-', '0');
	checkflags(strct, '+', ' ');
	n = check_display_block_o(strct, va);
	if (strct->prec > ft_count_base(n, 8))
		str = set_d_0(ft_itoa_base(n, 8), strct->prec - ft_count_base(n, 8));
	else if (strct->hash == 1 && strct->prec < ft_count_base(n, 8))
		str = set_hash(n);
	else
		str = ft_itoa_base(n, 8);
	if (strct->larg > (int)ft_strlen(str) && strct->larg > strct->prec)
	{
		larg = set_d_larg(strct, str);
		str = set_moins_d(strct, str, larg);
	}
//	if (strct->larg != 0 && strct->larg > strct->prec)
//		str = set_moins_d(strct, str, larg);
	g_ret += ft_strlen(str);
	return (str);
}
