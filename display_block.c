/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:51:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/15 13:01:34 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_block(t_struct *form, va_list va, int i)
{
	if (form->type == 's')
		check_display_block_s(form, va);
	if (form->type == 'S')
		check_display_block_s(form, va);
	if (form->type == 'p')
		;
	if (form->type == 'd')
		check_display_block_d(form, va);
	if (form->type == 'D')
		check_display_block_d(form, va);
	if (form->type == 'i')
		check_display_block_d(form, va);
	if (form->type == 'o')
		;
	if (form->type == 'O')
		;
	else
		return (display_block_2(form, va, i));
	return (i);
}

int	display_block_2(t_struct *form, va_list va, int i)
{
	if (form->type == 'u')
		;
	else if (form->type == 'U')
		;
	else if (form->type == 'x')
		check_display_block_x(form, va);
	else if (form->type == 'X')
		;
	else if (form->type == 'c')
		check_display_block_c(form, va);
	else if (form->type == 'C')
		check_display_block_c(form, va);
	return (i);
}
