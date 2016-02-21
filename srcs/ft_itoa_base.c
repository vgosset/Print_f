#include "ft_printf.h"

static	char	*unsigned_itoa_base(unsigned long nbr, int base)
{
	char			*ret;
	int				size;

	ret = NULL;
	size = ft_count_base((unsigned long)nbr, base);
	if ((ret = (char *)malloc(sizeof(char) * size + 1)))
	{
		ret[size--] = '\0';
		while (size >= 0)
		{
			if (base > 10)
			{
				ret[size] = (nbr % base) >= 10 ?
				(nbr % base) - 10 + 'a' : (nbr % base) + '0';
			}
			else
				ret[size] = (nbr % base) + '0';
			nbr /= base;
			size--;
		}
	}
	return (ret);
}

char		*ft_itoa_base(long long nbr, int base)
{
	char			*ret;
	int				size;
	int				is_neg;

	if (base != 10)
		return (unsigned_itoa_base((unsigned long)nbr, base));
	ret = NULL;
	size = nbr < 0 ? 1 : 0;
	is_neg = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	size += ft_count(nbr);
	if ((ret = (char *)malloc(sizeof(char) * size + 1)))
	{
		ret[size--] = '\0';
		while (nbr >= 0 && size >= 0)
		{
			ret[size--] = (nbr % base) + '0';
			nbr /= base;
		}
		if (is_neg == 1)
			ret[++size] = '-';
	}
	return (ret);
}
