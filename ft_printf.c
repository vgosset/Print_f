/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:26:19 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/20 16:33:47 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_struct *form)
{
	form->block = NULL;
	form->hash = 0;
	form->minus = 0;
	form->positive = 0;
	form->zero = 0;
	form->space = 0;
	form->large = 0;
	form->prec = 0;
	form->size = 0;
	form->type = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		va;
	int			i;

	va_start(va, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((check_format(format + i + 1)) == 1)
				return (1);
		}
		i++;
	}
	va_end(va);
	return (0);
}

int	main()
{
	char *string;

	string = "Puuuuuuuuuuuuuuuuh";
	ft_printf("%s", string);
	return (0);
}
