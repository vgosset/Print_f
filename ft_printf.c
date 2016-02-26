/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:26:19 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/25 22:45:06 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"
void	init_struct(t_struct *form)
{
	form->block = NULL;
	form->hash = 0;
	form->moins = 0;
	form->plus = 0;
	form->zero = 0;
	form->space = 0;
	form->larg = 0;
	form->prec = -1;
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

	g_ret = 0;
	va_start(va, format);
	i = 0;
/*	while (format[i])
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
*/	set_format(format, va);
	va_end(va);
	return (g_ret);
}

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	setlocale(LC_ALL, "fr_FR.UTF-8");
	wchar_t	*c;
	wchar_t e;
	unsigned long	a;

	c = L"我éabcfeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaf";
	e = L'我';
	a = -123456789;
	printf(" / True : %d\n", printf("%#-33.18lO", a));
	ft_printf(" / My   : %d\n", ft_printf("%#-33.18lO", a));
	return (0);
}
