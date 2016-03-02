/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:58:18 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/02 17:12:30 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_d_0(t_struct *form, char *str)
{
	char	*str0;
	int		nbr0;
	int		i;
	int		j;

	if (form->prec == -1 || form->prec < (int)ft_strlen(str))
		return (NULL);
	j = form->hash == 1 ? 2 : 0;
	nbr0 = form->prec - (int)ft_strlen(str);
	str0 = ft_strnew(nbr0 + 1);
	i = 0;
	while (i < nbr0 + j)
		str0[i++] = '0';
	str0[i] = '\0';
	return (str0);
}

static char	*set_d_larg(t_struct *form, char *str)
{
	char	*larg;
	int		j;
	int		x;

	j = form->prec > -1 ? form->prec : 0;
	x = form->hash == 1 ? 2 : 0;
	larg = NULL;
	if (form->larg == 0)
		return (NULL);
	if (form->zero == 1 && form->prec == -1)
		larg = place(form->larg - (int)ft_strlen(str) - x, '0');
	else
		larg = place(form->larg - ((int)ft_strlen(str) - j + x), ' ');
	return (larg);
}

static char	*set_moins_d(t_struct *form, char *str, char *larg)
{
	char	*new;

	if (form->moins == 0 || form->larg > form->prec)
	{
		if (form->hash == 1 && form->zero == 0 && form->prec == -1)
		{
			new = ft_strjoin(ft_strjoin(larg + 2, "0x"), str);
			form->hash = 0;
		}
		else if (form->hash == 1 && form->zero == 1 && form->prec == -1)
		{
			new = ft_strjoin(ft_strjoin("0x", larg + 2), str);
			form->hash = 0;
		}
		else if (form->hash == 1 && form->zero == 1 && form->prec > -1)
		{
			new = ft_strjoin(ft_strjoin(larg, "0x"), str + 2);
			form->hash = 0;
		}
		else
			new = ft_strjoin(larg, str);
	}
	else
		new = ft_strjoin(str, larg);
	return (new);
}

static char	*set_hash(t_struct *form, char *str, char *prec, char *larg)
{
	char	*tmp;

	tmp = ft_strjoin(prec, str);
	if (form->hash == 1 && form->zero == 0)
		tmp = prec == NULL ? ft_strjoin("0x", tmp) : ft_strjoin("0x", tmp + 2);
	if (form->larg > (int)ft_strlen(tmp))
	{
		if (form->zero == 1)
		{
			if (form->hash == 1)
			{
				tmp = ft_strjoin("0x", larg);
			}
			tmp = form->hash == 0 ? tmp = ft_strjoin(larg, tmp) : ft_strjoin(tmp, str);
		}
		else if (form->moins == 1)
			tmp = ft_strjoin(tmp, larg);
		else
			tmp = ft_strjoin(larg, tmp);
	}
	return (tmp);
}

char	*set_hex(t_struct *form, va_list va)
{
	char		*tab[4];
	uintmax_t	n;

	checkflags(form, '-', '0');
	checkflags(form, '+', ' ');
	n = check_display_block_x(form, va);
	n == 0 && form->hash == 1 ? form->hash = 0 : 42;
	tab[0] = ft_itoa_base(n, 16);
	tab[1] = set_d_0(form, tab[0]);
	tab[2] = set_d_larg(form, tab[0]);
	tab[3] = set_hash(form, tab[0], tab[1], tab[2]);
	if (form->type == 'X')
		tab[3] = set_upper(tab[3]);
	g_ret += ft_strlen(tab[3]);
	return (tab[3]);
}
