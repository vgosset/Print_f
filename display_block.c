/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:51:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/26 20:09:56 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_block(t_struct *form, va_list va, int i)
{
	if (form->type == 'c')
		ft_putchar(va_arg(va, int));
	if (form->type == 's')
		ft_putstr(va_arg(va, char *));
	return (i);
}
