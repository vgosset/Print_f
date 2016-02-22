/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:02:28 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/22 18:03:31 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*strplace(int n, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(n);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

static char	*set_d_0(char *str, int nbr0)
{
	char	*str0;
	char	*new;
	int		i;

	str0 = ft_strnew(nbr0 + 1);
	i = 0;
	while (i <= nbr0)
	{
		str0[i] = '0';
		i++;
	}
	str0[i] = '\0';
	new = ft_strjoin(str0, str);
	return (new);
}

static char	*set_d_larg(t_struct *form, char *str)
{
	char *larg;

	if (form->zero == 1)
		larg = strplace((size_t)form->larg - ft_strlen(str), '0');
	else
		larg = strplace((size_t)form->larg - ft_strlen(str), ' ');
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

char	*set_d(t_struct *form, char *nbr)
{
	char	*larg;
	char	*str;

	larg = NULL;
	if ((size_t)form->prec < ft_strlen(nbr))
		str = nbr;
	else if ((size_t)form->prec > ft_strlen(nbr))
		str = set_d_0(nbr, ((size_t)form->prec) - ft_strlen(nbr) - 1);
	else
		str = set_d_0(nbr, ((size_t)form->prec) - ft_strlen(nbr));
	if (form->plus == 1)
		str = set_d_plus_space(str, '+');
	if (form->space == 1 && (size_t)form->larg > ft_strlen(nbr))
		str = set_d_plus_space(str, ' ');
	if ((size_t)form->larg > ft_strlen(str))
		larg = set_d_larg(form, str);
	if (form->moins == 1)
		str = ft_strjoin(str, larg);
	else
		str = ft_strjoin(larg, str);
	if ((size_t)form->prec > ft_strlen(nbr) && nbr[0] == '-')
	{
		str[0] = '-';
		str[(form->prec - ft_strlen(nbr)) + 1] = '0';
	}
	g_ret = ft_strlen(str);
	return (str);
}
