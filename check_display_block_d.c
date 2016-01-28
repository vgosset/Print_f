#include "ft_printf.h"

void	check_display_block_d(t_struct *form, va_list va)
{
	if (form->l <= 0)
		ft_putnbr(va_arg(va, int));
}
