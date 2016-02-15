/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:45:51 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/15 16:09:42 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
