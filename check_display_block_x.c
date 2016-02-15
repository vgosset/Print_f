/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:52:30 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/15 12:54:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_x(t_struct *form, va_list va)
{
	if (form->type == 'x')
		ft_puthex(va_arg(va, long));
}
