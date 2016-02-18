/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:51:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/18 17:53:08 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_block(t_struct *form, va_list va, int i)
{
	if (form->type == 's' || form->type == 'S')
		check_display_block_s(form, va);
	else if (form->type == 'p')
		;
	else if (form->type == 'd' || form->type == 'D' || form->type == 'i')
		check_display_block_d(form, va);
	else if (form->type == 'o' || form->type == 'O')
		check_display_block_o(form, va);
	else if (form->type == 'u' || form->type == 'U')
		check_display_block_u(form, va);
	else if (form->type == 'x' || form->type == 'X')
		check_display_block_x(form, va);
	else if (form->type == 'c' || form->type == 'C')
		check_display_block_c(form, va);
	return (i);
}
