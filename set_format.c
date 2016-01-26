/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:44:06 by jle-quer          #+#    #+#             */
/*   Updated: 2016/01/26 16:33:59 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char format)
{
	if (format == 's' || format == 'S' || format == 'p'
		|| format == 'd' || format == 'D' || format == 'i'
		|| format == 'o' || format == 'O' || format == 'u'
		|| format == 'U' || format == 'x' || format == 'X'
		|| format == 'c' || format == 'C' || format == 'E')
		return (1);
	else
		return (0);
}

int	check_block(char *block, t_struct *form)
{
	int	i;

	i = 0;
	form->block = block;
	while (form->block[i])
	{
		if (form->block[i] == form->type)
		{
			if (form->block[i + 1] != '\0')
				return (-1);
		}
		i++;
	}
	if ((form->hh + form->h + form->l + form->ll + form->j + form->z) > 1)
		return (-1);
	if (form->type == 0)
		return (-1);
	if ((form->minus > 0 && form->zero > 0)
			|| (form->positive > 0 && form->space > 0))
		return (-1);
	return (1);
}
