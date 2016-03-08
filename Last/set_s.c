/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 22:54:36 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/08 15:06:16 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_larg(t_struct *form, char *str)
{
	char	*new;

	new = NULL;
	if (form->larg > (int)ft_strlen(str))
		new = place_s(form->larg - (int)ft_strlen(str), ' ');
	return (new);
}

void	set_s(t_struct *form, va_list va)
{
	char	*str;
	char	*larg;
	char	*tmp;

	larg = NULL;
	tmp = va_arg(va, char *);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	if (form->prec != -1 && form->prec < (int)ft_strlen(tmp))
		str = ft_strsub(tmp, 0, form->prec);
	else
		str = ft_strdup(tmp);
	if (form->larg > (int)ft_strlen(str))
		larg = set_larg(form, str);
	if (form->prec == -1 && form->larg != 0 && form->moins == 0)
		tmp = ft_strjoin(larg, str);
	else if (form->moins == 1)
		tmp = ft_strjoin(str, larg);
	else
		tmp = ft_strjoin(larg, str);
	str = ft_strdup(tmp);
	free(tmp);
	free(larg);
	g_ret += ft_strlen(str);
	ft_putstr(str);
}
