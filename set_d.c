/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:14:49 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/25 17:51:29 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_d_0(char *str, int nbr0, long long n)
{
	char	*str0;
	char	*new;
	int		i;
	int		j;

	j = n < 0 ? 2 : 0;
	str0 = ft_strnew(nbr0 + 2);
	i = 0;
	if (str[0] == '-')
	{
		str0[0] = '-';
		i = 1;
	}
	while (i < nbr0 + j)
	{
		str0[i] = '0';
		i++;
	}
	str0[i] = '\0';
	if (n == -2147483648)
		str = ft_strdup("2147483648");
	else if (n < 0 && n > -2147483648)
		str = ft_itoa(-n);
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

static char	*set_d_plus_space(char *str, char c)
{
	char *new;

	new = ft_strnew(1);
	new[0] = c;
	str = ft_strjoin(new, str);
	return (str);
}

static char	*set_moins_d(t_struct *strct, char *str, char *larg)
{
	char *new;

	if (strct->moins == 0)
		new = ft_strjoin(larg, str);
	else
		new = ft_strjoin(str, larg);
	return (new);
}

char	*set_d(t_struct *strct, va_list va)
{
	char		*larg;
	char		*str;
	long long	n;

	checkflags(strct, '-', '0');
	checkflags(strct, '+', ' ');
	n = check_display_block_d(strct, va);
	if (strct->prec > ft_count(n))
		str = set_d_0(ft_itoa(n), strct->prec - ft_count(n), n);
	else
		str = ft_itoa(n);
	if (strct->plus == 1 && n > 0)
		str = set_d_plus_space(str, '+');
	if (strct->space == 1 && n > 0)
		str = set_d_plus_space(str, ' ');
	if (strct->larg > (int)ft_strlen(str) && strct->larg > strct->prec)
		larg = set_d_larg(strct, str);
	if (strct->larg != 0  && strct->larg > strct->prec)
		str = set_moins_d(strct, str, larg);
	g_ret += ft_strlen(str);
	return (str);
}
