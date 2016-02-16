/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_o.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:58:21 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/16 13:20:20 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_o(t_struct *form, va_list va)
{
	if (form->type == 'o' && form->l < 1)
		;
	else if (form->type == 'o' && form->l > 0)
		;
	else if (form->type == 'O' && form->l < 1)
		;
	else if (form->type == 'O' && form->l > 0)
		;
	else if (form->type == 'o' && form->h < 1)
		;
	else if (form->type == 'o' && form->h > 0)
		;
	else if (form->type == 'O' && form->h < 1)
		;
	else if (form->type == 'O' && form->h > 0)
		;
}
