/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:26:19 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/22 13:58:24 by jle-quer         ###   ########.fr       */
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
	form->minimal_large = 0;
	form->prec = 0;
	form->size = 0;
	form->type = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list		va;
	int			i;
	int			len;

	va_start(va, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if ((check_format(format + i + 1)) == 1)
				return (1);
		}
		i++;
	}
	va_end(va);
	return (len);
}

int	main()
{
	char *string;

	string = "Puuuuuuuuuuuuuuuuh";
	ft_printf("%s", string);
	return (0);
}
