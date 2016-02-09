/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:30:53 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/09 13:24:54 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	char	*binary;

	binary = ui_to_bin((unsigned int)c);
	
}

char	*ui_to_bin(unsigned int u)
{
	char			*binary;
	unsigned int	i;

	if (!(binary == (char *)malloc(sizeof(char) * 33)))
		return (NULL);
	ft_bzero(binary, 33);
	i = 31;

	while (u > 0)
	{
		binary[i] = (u % 2) + '0';
		u /= 2;
		i--;
	}
	return (binary);
}
