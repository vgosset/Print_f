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

static char	*set_d_0(t_struct *form, char *str, int nbr0)
{
	char	*str0;
	char	*new;
	int		i;
	int		j;

	j = form->hash == 1 ? 2 : 0;
	str0 = ft_strnew(nbr0 + 1);
	i = 0;
	while (i < nbr0 + j)
		str0[i++] = '0';
	str0[i] = '\0';
	new = ft_strjoin(str0, str);
	return (new);
}

static char	*set_d_larg(t_struct *form, char *str)
{
	char *larg;

	if (form->zero == 1 && form->prec == -1)
		larg = place(form->larg - ft_strlen(str), '0');
	else
		larg = place(form->larg - ft_strlen(str), ' ');
	return (larg);
}

static char	*set_moins_d(t_struct *form, char *str, char *larg)
{
	char	*new;

	if (form->moins == 0)
		new = ft_strjoin(larg, str);
	else
		new = ft_strjoin(str, larg);
	return (new);
}

static char	*set_hash(t_struct *form, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		str[i] = '0';
		str[i + 1] = 'x';
	}
	else if (str[i] == '0' && str[i + 1] == '0')
	{
		str[i] = '0';
		str[i + 1] = 'x';
	}
	else
		str = ft_strjoin("0x", str);
	if (form->larg > 0 && (int)ft_strlen(str) > form->larg)
	{
		tmp = ft_strsub(str, 0, ft_strlen(str) -2);
		str = ft_strdup(tmp);
	}
	return (str);
}

char	*set_hex(t_struct *form, va_list va)
{
	char		*tab[3];
	uintmax_t	n;

	checkflags(form, '-', '0');
	checkflags(form, '+', ' ');
	n = check_display_block_x(form, va);
	tab[1] = form->prec > ft_count_base(n, 16) ?
		set_d_0(form, ft_itoa_base(n, 16), form->prec -
				ft_count_base(n, 16)) : ft_itoa_base(n, 16);
	if (form->larg > (int)ft_strlen(tab[1]) && form->larg > form->prec)
		tab[0] = set_d_larg(form, tab[1]);
	if (form->larg != 0 && form->larg > form->prec)
		tab[1] = set_moins_d(form, tab[1], tab[0]);
	if (form->hash == 1)
	{
		tab[2] = ft_strdup(tab[1]);
		tab[1] = set_hash(form, tab[2]);
	}
	if (form->type == 'X')
	{
		tab[2] = set_upper(tab[1]);
		tab[1] = tab[2];
	}
	g_ret += ft_strlen(tab[1]);
	return (tab[1]);
}
