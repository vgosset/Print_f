/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:46:46 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/16 13:13:24 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char format)
{
	if (format == 's' || format == 'S' || format == 'p'
		|| format == 'd' || format == 'D' || format == 'i'
		|| format == 'o' || format == 'O' || format == 'u'
		|| format == 'U' || format == 'x' || format == 'X'
		|| format == 'c' || format == 'C')
		return (1);
	else
		return (0);
}

int	check_block(char *block, t_struct *form)
{
	int	i;

	i = 0;
	form->block = block;
	if (form->type == 0)
		return (-1);
	if (form->block[ft_strlen(block) - 1] != form->type)
		return (-1);
	if (form->block[ft_strlen(block)] != '\0')
		return (-1);
	if ((form->hh + form->h + form->l + form->ll + form->j + form->z) > 1)
		return (-1);
	if ((form->moins > 0 && form->zero > 0)
			|| (form->plus > 0 && form->space > 0))
		return (-1);
	return (1);
}
