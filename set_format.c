/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:01:00 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/27 19:00:27 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_format(const char *format, va_list va)
{
	int	i;

	i = 0;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%' && format[i + 1] != '%')
			i += (set_block(format + i + 1, va)) + 2;
	}
	return (1);
}

int	set_block(const char *format, va_list va)
{
	t_struct	form;
	int			i;

	i = 0;
	init_struct(&form);
	while ((check_options(format[i], &form)) == 1)
		i++;
	while ((check_minimal_large(format[i], &form)) == 1)
		i++;
	if (format[i] == '.')
	{
		while ((check_precision(format[++i], &form)) == 1)
			continue;
	}
	while (format[i] == 'h' || format[i] == 'l' || format[i] == 'j'
			|| format[i] == 'z')
	{
		check_size_modifier(format + i, &form);
		i++;
		if ((&form)->hh > 0 || (&form)->ll > 0)
			i++;
	}
	if ((check_type(format[i])) == 1)
		(&form)->type = format[i];
	return (display_block(&form, va, i));
}
