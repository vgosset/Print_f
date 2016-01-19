/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:26:19 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/19 16:00:43 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(char *format, int i, va_list va)
{
	while (format[i++])
	{
		if (format[i] == 'd')
		{
			ft_putnbr(va_arg(va, int));
			return (1);
		}
		else if (format[i] == 'c')
		{
			ft_putchar(va_arg(va, char));
			return (1);
		}
		else if (format[i] == 's')
		{
			ft_putstr(va_arg(va, char *));
			return (1);
		}
	}
	return (0);
} 

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		i;

	va_start(format, va);
	i = 0;
	while (format[i++])
	{
		if (format[i] == '%')
			if ((check_next(format, i, va)) == 1)
				return (1);
	}
	va_end(va);
	return (0);
}

int	main()
{
	char *string;

	string = "Puuuuuuuuuull-Up";
	ft_printf("%s", string);
	return (0);
}
