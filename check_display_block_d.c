/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:50:58 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/18 17:49:56 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_display_block_d(t_struct *form, va_list va)
{
	long long	p;

	if (form->l > 0 || form->ll > 0 || form->type == 'D')
	{
		p = va_arg(va, long long);
		ft_putlong_nbr(p);
	}
	else if (form->j > 0)
	{
		p = va_arg(va, intmax_t);
		ft_putlong_nbr(p);
	}
	else if (form->hh > 0)
	{
		p = (signed char)va_arg(va, int);
		ft_putsignedchar_nbr(p);
	}
	else
		check_display_block_d_2(form, va);
}

void	check_display_block_d_2(t_struct *form, va_list va)
{
	long long	p;

	if (form->h > 0)
	{
		p = (short)va_arg(va, int);
		ft_putshort_nbr(p);
	}
	else if (form->z > 0)
	{
		p = va_arg(va, size_t);
		ft_putlong_nbr(p);
	}
	else
	{
		p = va_arg(va, int);
		ft_putnbr(p);
	}
}
