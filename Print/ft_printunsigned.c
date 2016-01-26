#include "libprt.h"

int		ft_printunsigned(va_list ap)
{
	char			*p;
	unsigned int	c;

	c = va_arg(ap, unsigned int);
	p = ft_utoa(c);
	ft_putstr(p);
	return (ft_strlen(p));
}
