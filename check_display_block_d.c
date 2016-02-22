/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:50:58 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/22 12:51:13 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_display_block_d(t_struct *form, va_list va)
{
	long long	p;

	if (form->l > 0 || form->ll > 0 || form->type == 'D')
		p = va_arg(va, long long);
	else if (form->j > 0)
		p = va_arg(va, intmax_t);
	else if (form->hh > 0)
		p = (signed char)va_arg(va, int);
	else
		return (check_display_block_d_2(form, va));
	g_ret += ft_count(p);
	return (ft_itoa_base(p, 10));
}

char	*check_display_block_d_2(t_struct *form, va_list va)
{
	long long	p;

	if (form->h > 0)
		p = (short)va_arg(va, int);
	else if (form->z > 0)
		p = va_arg(va, size_t);
	else
		p = va_arg(va, int);
	g_ret += ft_count(p);
	return (ft_itoa_base(p, 10));
}
