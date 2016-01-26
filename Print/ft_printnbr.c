#include "libprt.h"

int		ft_printnbr(va_list ap)
{
	int		c;
	char	*p;

	c = va_arg(ap, int);
	p = ft_itoa(c);
	ft_putstr(p);
	return (ft_strlen(p));
}
