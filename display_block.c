/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:51:57 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/27 04:33:41 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_block(t_struct *form, va_list va, int i)
{
	char	*str;

	str = NULL;
	if (form->type == 'S' || (form->type == 's' && form->l == 1))
		set_wchar_s(form, va);
	else if (form->type == 's')
		set_s(form, va);
	else if (form->type == 'p')
		str = set_p(form, va);
	else if (form->type == 'd' || form->type == 'D' || form->type == 'i')
		str = set_d(form, va);
	else if (form->type == 'o' || form->type == 'O')
		str = set_octal(form, va);
	else if (form->type == 'u' || form->type == 'U')
		str = set_u(form, va);
	else if (form->type == 'x' || form->type == 'X')
		str = set_hex(form, va);
	else if (form->type == 'c' || form->type == 'C')
		set_c(form, va);
	if (form->type != 'c' && form->type != 'C'
			&& form->type != 's' && form->type != 'S')
		ft_putstr(str);
	return (i);
}
