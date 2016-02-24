/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 17:21:34 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/24 17:30:52 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_d_0(t_struct *strct, char *str, int nbr0)
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
		larg = strplace(strct->larg - ft_strlen(str), '0');
	else
		larg = strplace(strct->larg - ft_strlen(str), ' ');
	return (larg);
}

static char	*set_d_plus_space(t_struct *strct, char *str, char c)
{
	char *new;

	new = ft_strnew(1);
	new[0] = c;
	str = ft_strjoin(new, str);
	return (str);
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
		str = set_d_0(strct, ft_itoa_base(n, 8), strct->prec - ft_count_base(n, 8));
	else
		str = ft_itoa_base(n, 8);
	if (strct->plus == 1)
		str = set_d_plus_space(strct, str, '+');
	if (strct->space == 1)
		str = set_d_plus_space(strct, str, ' ');
	if (strct->larg > ft_strlen(str))
		larg = set_d_larg(strct, str);
	if (strct->moins == 1)
		str = ft_strjoin(str, larg);
	else
		str = ft_strjoin(larg, str);
	return (str);
}
