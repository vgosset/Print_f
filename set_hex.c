/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:58:18 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/26 22:56:21 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_d_0(t_struct *strct, char *str, int nbr0)
{
	char	*str0;
	char	*new;
	int		i;
	int		j;

	j = strct->hash == 1 ? 2 : 0;
	str0 = ft_strnew(nbr0 + 1);
	i = 0;
	while (i < nbr0 + j)
		str0[i++] = '0';
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

static char	*set_d_plus_space(t_struct *strct, char *str, char c)
{
	char *new;

	new = ft_strnew(1 + 1);
	new[0] = c;
	new[1] = '\0';
	str = ft_strjoin(new, str);
	return (str);
}

static char	*set_moins_d(t_struct *strct, char *str, char *larg)
{
	char	*new;

	if (strct->moins == 0)
		new = ft_strjoin(larg, str);
	else
		new = ft_strjoin(str, larg);
	return (new);
}

static char	*set_hash(t_struct *strct, char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	str[i] = '0';
	str[i + 1] = 'x';
	return (str);
}

static char	*set_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*set_hex(t_struct *strct, va_list va)
{
	char		*tab[3];
	uintmax_t	n;

	checkflags(strct, '-', '0');
	checkflags(strct, '+', ' ');
	n = check_display_block_x(strct, va);
	tab[1] = strct->prec > ft_count_base(n, 16) ?
		set_d_0(strct, ft_itoa_base(n, 16), strct->prec -
				ft_count_base(n, 16)) : ft_itoa_base(n, 16);
	if (strct->larg > ft_strlen(tab[1]) && strct->larg > strct->prec)
		tab[0] = set_d_larg(strct, tab[1]);
	if (strct->larg != 0 && strct->larg > strct->prec)
		tab[1] = set_moins_d(strct, tab[1], tab[0]);
	if (strct->hash == 1)
	{
		tab[2] = ft_strdup(tab[1]);
		tab[1] = set_hash(strct, tab[2]);
	}
	if (strct->type == 'X')
	{
		tab[2] = set_upper(tab[1]);
		tab[1] = tab[2];
	}
	g_ret += ft_strlen(tab[1]);
	return (tab[1]);
}
