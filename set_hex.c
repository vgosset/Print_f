/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:58:18 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/25 19:50:55 by jle-quer         ###   ########.fr       */
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
		larg = strplace(strct->larg - ft_strlen(str), '0');
	else
		larg = strplace(strct->larg - ft_strlen(str), ' ');
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
	char		*larg;
	char		*str;
	char		*tmp;
	uintmax_t	n;

	checkflags(strct, '-', '0');
	checkflags(strct, '+', ' ');
	n = check_display_block_x(strct, va);
	if (strct->prec > ft_count_base(n, 16))
		str = set_d_0(strct, ft_itoa_base(n, 16), strct->prec - ft_count_base(n, 16));
	else
		str = ft_itoa_base(n, 16);
	if (strct->larg > ft_strlen(str) && strct->larg > strct->prec)
		larg = set_d_larg(strct, str);
	if (strct->larg != 0 && strct->larg > strct->prec)
		str = set_moins_d(strct, str, larg);
	if (strct->hash == 1)
	{
		tmp = ft_strdup(str);
		str = set_hash(strct, tmp);
	}
	if (strct->type == 'X')
	{
		tmp = set_upper(str);
		str = tmp;
	}
	g_ret += ft_strlen(str);
	return (str);
}
