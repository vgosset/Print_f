/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 04:27:39 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/27 04:54:24 by jle-quer         ###   ########.fr       */
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

char		*set_p(t_struct *strct, va_list va)
{
	char			*larg;
	char			*str;
	unsigned long	n;

	checkflags(strct, '-', '0');
	checkflags(strct, '+', ' ');
	n = check_display_block_p(va);
	if (strct->prec > ft_count_base(n, 16))
		str = ft_strjoin("0x", set_d_0(ft_itoa_base(n, 16),
				strct->prec - ft_count_base(n, 16)));
	else
		str = ft_strjoin("0x", ft_itoa_base(n, 16));
	if (strct->larg > (int)ft_strlen(str) && strct->larg > strct->prec)
	{
		larg = set_d_larg(strct, str);
		str = set_moins_d(strct, str, larg);
	}
	g_ret += ft_strlen(str);
	return (str);
}
