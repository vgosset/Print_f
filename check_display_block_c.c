/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:27:03 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/19 15:30:10 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_c(t_struct *form, va_list va)
{
	if (form->l <= 0 && form->type == 'c')
	{
		ft_putchar(va_arg(va, int));
		g_ret += 1;
	}
	else if (form->l > 0 || form->type == 'C')
	{
		wchar_t	a;

		a = va_arg(va, wchar_t);
		ft_putwchar(a);
		g_ret += ft_count_wchar((unsigned int)a);
	}
}
