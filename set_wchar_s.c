/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wchar_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 01:45:16 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/27 03:41:25 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static wchar_t	*set_larg(t_struct *strct, wchar_t *str)
{
	if (strct->larg > (int)ft_strlen(str))
		str = place_s(strct, strct->larg - (int)ft_strlen(str), ' ');
	return (str);
}
*/
static	int	wstr_len(wchar_t *str)
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

void		set_wchar_s(t_struct *form, va_list va)
{
	wchar_t	*tmp;
	char	*str;
	int		wchar_len;
	int		i;

	i = 0;
	str = NULL;
	tmp = va_arg(va, wchar_t*);
	wchar_len = wstr_len(tmp);
	if (form->larg > wchar_len)
		str = place(form->larg - wchar_len, ' ');
	if (form->moins == 0 && str)
	{
		ft_putstr(str);
		ft_putwstr(tmp);
	}
	else if (form->moins == 1 && str)
	{
		ft_putwstr(tmp);
		ft_putstr(str);
	}
	else if (!str)
		ft_putwstr(tmp);
	g_ret += str != NULL ? wchar_len + (int)ft_strlen(str) : wchar_len;
}
