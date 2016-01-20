/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:50:13 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/20 16:53:09 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format)
{
	t_struct	form;
	int			i;

	i = 0;
	init_struct(&form);
	while (format[i])
	{
		if (format[i] == '%' && format [i + 1] != '%')
		{
			if (check_block(format + i + 1, &form) == 1)
				i++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_block(const char *format, t_struct *form)
{
	int i;

	i = 0;
	while (format[i] && format[i] = '-' || format[i] = '+' || format[i] = '#'
			|| format[i] = '0' || format[i] = ' ')
	{
		if (format[i] == '-')
			form->minus = 1;
		else if (format[i] == '+')
			form->positive = 1;
		else if (format[i] == '#')
			form->hash = 1;
		else if (format[i] == '0')
			form->zero = 1;
		else if (format[i] == ' ')
			form->space = 1;
		i++;
	}
}
