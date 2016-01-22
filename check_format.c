/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:50:13 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/22 13:58:35 by jle-quer         ###   ########.fr       */
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
		while (check_options(format[i], &form) == 1)
			i++;
		while (format[i] - 48 >= '0' && format[i] - 48 <= '9')
		{
			check_minimal_large(format[i], &form);
			i++;
		}
		if (format[i] == '.')
			check_precision(format + 1, &form);
		i++;
	}
	return (1);
}

int	check_options(const char format, t_struct *form)
{
	if (format != '-' || format != '+' || format != '#' || format != '0'
			|| format != ' ')
		return (0);
	else if (format == '-')
		form->minus += 1;
	else if (format == '+')
		form->positive += 1;
	else if (format == '#')
		form->hash += 1;
	else if (format == '0')
		form->zero += 1;
	else if (format == ' ')
		form->space += 1;
	return (1);
}

void	check_minimal_large(const char format, t_struct *form)
{
	form->minimal_large = form->minimal_large * 10 + (format - 48);
}

void	check_precision(const char *format, t_struct *form)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] - 48 >= '0' && format[i] - 48 <= '9'))
	{
		form->prec = form->prec * 10 + format[i] - 48;
		i++;
	}
}
