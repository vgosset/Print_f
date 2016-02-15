/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:26:19 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/15 18:34:11 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <locale.h>
#include <wchar.h>
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
	form->hh = 0;
	form->h = 0;
	form->l = 0;
	form->ll = 0;
	form->j = 0;
	form->z = 0;
	form->type = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		va;
	int			i;
	int			len;

	va_start(va, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			if ((check_format(format + i + 1)) == -1)
				return (-1);
		}
		i++;
	}
	len = set_format(format, va);
	va_end(va);
	return (len);
}

#include <stdio.h>

int		main(void)
{
	setlocale(LC_ALL, "fr_FR.UTF-8");
	wchar_t	*c;
	unsigned short	a;

	c = L"我";
	a = 52500;
	printf("True : %#hx\n", a);
	ft_printf("My : %#hx\n", a);
	return (0);
}
