#include "libprt.h"

int		ft_printvoid(va_list ap)
{
	char			*p;
	unsigned long	c;

	ft_putstr("0x");
	c = va_arg(ap, unsigned long);
	p = ft_htoa(c);
	ft_putstr(p);
	return (ft_strlen(p) + 2);
}
