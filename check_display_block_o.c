/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_o.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:58:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/16 17:29:44 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_o(t_struct *form, va_list va)
{
	if (form->l > 0)
	{
		ft_putoctal(va_arg(va, unsigned long));
	}
	else if (form->h > 0)
	{
		ft_putoctal((unsigned short)va_arg(va, unsigned int));
	}
	else if (form->hh > 0)
		ft_putoctal((unsigned char)va_arg(va, unsigned int));
	else if (form->type == 'O')
	{
		ft_putoctal(va_arg(va, unsigned long));
	}
}
