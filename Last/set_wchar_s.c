/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wchar_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:45:16 by jle-quer          #+#    #+#             */
/*   Updated: 2016/03/08 14:02:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		wstr_len(wchar_t *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		ret += ft_count_wchar(str[i]);
		i++;
	}
	return (ret);
}

static	void	set_wchar_null(t_struct *form)
{
	char	*str;
	char	*larg;

	str = ft_strdup("(null)");
	larg = NULL;
	if (form->prec != -1 && form->prec < (int)ft_strlen(str))
		str = ft_strsub(str, 0, form->prec);
	if (form->larg > (int)ft_strlen(str))
		larg = set_larg(form, str);
	if (form->prec == -1 && form->larg != 0 && form->moins == 0)
		str = ft_strjoin(larg, str);
	else if (form->moins == 1)
		str = ft_strjoin(str, larg);
	else
		str = ft_strjoin(larg, str);
	free(larg);
	g_ret += ft_strlen(str);
	ft_putstr(str);
}

void			set_wchar_s(t_struct *form, va_list va)
{
	wchar_t	*tmp;
	char	*str;
	int		wchar_len;
	int		i;

	i = 0;
	str = NULL;
	tmp = va_arg(va, wchar_t*);
	if (tmp == NULL)
		return (set_wchar_null(form));
	wchar_len = wstr_len(tmp);
	if (form->larg > wchar_len && tmp != NULL)
		str = place(form->larg - wchar_len, ' ');
	if (form->moins == 0 && str && tmp != NULL)
	{
		ft_putstr(str);
		ft_putwstr(tmp);
	}
	else if (form->moins == 1 && str && tmp != NULL)
	{
		ft_putwstr(tmp);
		ft_putstr(str);
	}
	else if (!str && tmp != NULL)
		ft_putwstr(tmp);
	g_ret += str != NULL ? wchar_len + (int)ft_strlen(str) : wchar_len;
}
