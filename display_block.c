/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:51:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/27 19:05:53 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_block(t_struct *form, va_list va, int i)
{
	if (form->type == 's')
		check_display_block_s(form, va);
	if (form->type == 'S')
		;
	if (form->type == 'p')
		;
	if (form->type == 'd')
		check_display_block_d(form, va);
	if (form->type == 'D')
		;
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
		;
	else if (form->type == 'X')
		;
	else if (form->type == 'c')
		check_display_block_c(form, va);
	else if (form->type == 'C')
		;
	return (i);
}

void	check_display_block_c(t_struct *form, va_list va)
{
	if ((form->l) <= 0)
		ft_putchar(va_arg(va, int));
}

void	check_display_block_d(t_struct *form, va_list va)
{
	if (form->h <= 0)
		ft_putnbr(va_arg(va, int));
}

void	check_display_block_s(t_struct *form, va_list va)
{
	if (form->h <= 0)
		ft_putstr(va_arg(va, char *));
}
