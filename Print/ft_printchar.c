#include "libprt.h"

int		ft_printchar(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}
