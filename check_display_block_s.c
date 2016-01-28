#include "ft_printf.h"

void	check_display_block_s(t_struct *form, va_list va)
{
	if (form->l <= 0)
		ft_putstr(va_arg(va, char *));
}
