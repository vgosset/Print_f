/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsignedchar_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:32:37 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/18 17:35:49 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsignedchar_nbr(signed char nbr)
{
	if (nbr == -128)
	{
		ft_putstr("-128");
		return ;
	}
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		if (nbr >= 10)
			ft_putsignedchar_nbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
