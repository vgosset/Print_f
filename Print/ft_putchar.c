#include	<unistd.h>

int		ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
	return (1);
}
