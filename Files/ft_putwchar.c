/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 12:30:53 by jle-quer          #+#    #+#             */
/*   Updated: 2016/02/09 18:09:04 by jle-quer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t c)
{
	char	*bits;
	char	**mask;

	bits = ui_to_bits((unsigned int)c);
	mask = uni_mask(bits);

}

char	*ui_to_bits(unsigned int u)
{
	char			*bits;
	unsigned int	i;

	if (!(bits == (char *)malloc(sizeof(char) * 33)))
		return (NULL);
	ft_bzero(bits, 33);
	i = 31;

	while (u > 0)
	{
		bits[i] = (u % 2) + '0';
		u /= 2;
		i--;
	}
	return (bits);
}

char	**uni_mask(char *bits)
{
	char	*mask;
	size_t	bits_len;
	int		mask_len;

	bits_len = 31;
	while (bits[bits_len])
		bits_len--;
	bits_len = 31 - bits_len;
	if (bits_len > 7 && bits_len <= 11)
		mask = ft_strdup("110xxxxx 10xxxxxx");
	else if (bits_len > 11 && bits_len <= 16)
		mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else if (bits_len > 16)
		mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	mask_len = ft_strlen(mask) - 1;
	bits_len = 31;
	while (mask_len >= 0)
	{
		if (mask[mask_len] == 'x' && bits[bits_len])
		{
			mask[mask_len] = bits[bits_len];
			bits_len--;
		}
		else if (mask[mask_len] == 'x' && !bits[bits_len])
			mask[mask_len] = '0';
		mask_len--;
	}
}
