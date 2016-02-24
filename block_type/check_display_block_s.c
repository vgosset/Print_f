/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:11:12 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/19 15:37:54 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_s(t_struct *form, va_list va)
{
	if (form->l <= 0 && form->type == 's')
	{
		char	*str;
		int		i;

		i = 0;
		str = va_arg(va, char *);
		while (str[i])
		{
			ft_putchar(str[i]);
			g_ret += 1;
			i++;
		}
	}
	else if (form->l > 0 || form->type == 'S')
	{
		wchar_t	*wstr;
		int		i;

		i = 0;
		wstr = va_arg(va, wchar_t*);
		while (wstr[i])
		{
			ft_putwchar(wstr[i]);
			g_ret += ft_count_wchar((unsigned int)wstr[i]);
			i++;
		}
	}
}
