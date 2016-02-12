#include "ft_printf.h"

void	ft_putwstr(wchar_t *str)
{
	char	*bits;
	char	**mask;
	int		i;

	while (*str)
	{
		bits = ui_to_bits((unsigned int)*str);
		mask = uni_mask(bits);
		i = 0;
		while (mask && mask[i])
		{
			print_oct(mask[i]);
			free(mask[i]);
			i++;
		}
		free(bits);
		free(mask);
		str++;
	}
}
