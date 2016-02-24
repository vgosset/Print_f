/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:09:07 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/24 16:10:14 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkflags(t_struct *strct, char a, char b)
{
	if (a == '-' && b == '0')
	{
		if (strct->moins == 1 && strct->zero == 1)
			strct->zero = 0;
	}
	if (a == '+' && b == ' ')
	{
		if (strct->space == 1 && strct->plus == 1)
		strct->space = 0;
	}
}

char	*strplace(int n, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(n);
	while (i < n )
	{
		str[i] = c;
		i++;
	}
	return (str);
}
