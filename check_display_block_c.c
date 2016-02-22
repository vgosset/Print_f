/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_display_block_c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 12:27:03 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/22 13:17:38 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_display_block_c(t_struct *form, va_list va)
{
	char	*ret;

	ret = NULL;
	if ((ret = (char *)malloc(sizeof(char) * 2)))
	{
		if (form->l > 0 || form->type == 'C')
		{
			wchar_t	a;

			a = va_arg(va, wchar_t);
			ret[0] = a;
			ret[1] = '\0';
			g_ret += ft_count_wchar((unsigned int)a);
		}
		else if (form->l <= 0)
		{
			ret[0] = va_arg(va, int);
			ret[1] = '\0';
			g_ret += 1;
		}
	}
	return (ret);
}
