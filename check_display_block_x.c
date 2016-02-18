/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:52:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/18 17:48:19 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_x(t_struct *form, va_list va)
{
	if (form->hash > 0 && form->type == 'x')
		ft_putstr("0x");
	else if (form->hash > 0 && form->type == 'X')
		ft_putstr("0X");
	if (form->type == 'x' && form->l < 1)
		ft_puthex(va_arg(va, unsigned int));
	else if (form->type == 'x' && form->l > 0)
		ft_puthex(va_arg(va, unsigned long));
	else if (form->type == 'X' && form->l < 1)
		ft_puthex_x(va_arg(va, unsigned int));
	else if (form->type == 'X' && form->l > 0)
		ft_puthex_x(va_arg(va, unsigned long));
	else if (form->type == 'x' && form->h < 1)
		ft_puthex(va_arg(va, unsigned int));
	else if (form->type == 'x' && form->h > 0)
		ft_puthex((unsigned short)va_arg(va, unsigned int));
	else if (form->type == 'X' && form->h < 1)
		ft_puthex_x(va_arg(va, unsigned int));
	else if (form->type == 'X' && form->h > 0)
		ft_puthex_x((unsigned short)va_arg(va, unsigned int));
}
