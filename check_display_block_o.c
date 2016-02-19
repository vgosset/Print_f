/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_o.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:58:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/19 15:55:48 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_o(t_struct *form, va_list va)
{
	unsigned long p;

	if (form->l > 0 || form->ll > 0 || form->type == 'O')
		p = va_arg(va, unsigned long);
	else if (form->j > 0)
		p = va_arg(va, uintmax_t);
	else if (form->hh > 0)
		p = (unsigned char)va_arg(va, unsigned int);
	else if (form->h > 0)
		p = (unsigned short)va_arg(va, unsigned int);
	else if (form->z > 0)
		p = va_arg(va, size_t);
	else
		p = va_arg(va, unsigned int);
	g_ret += ft_count((long)p);
	ft_putoctal(p);
}
