#include "ft_printf.h"

void	set_c(t_struct *form, va_list va)
{
	wchar_t		c;
	char		*larg;
	int			y;

	larg = NULL;
	c = form->type == 'C' || form->l == 1 ? va_arg(va, wchar_t) : va_arg(va, int);
	y = form->type == 'C' || form->l == 1 ? ft_count_wchar(c) : 1;
	if (form->larg > 0)
	{
		larg = place(form->larg - y, ' ');
		if (form->moins == 1)
		{
			form->type == 'C' || form->l == 1 ? ft_putwchar(c) : ft_putchar(c);
			ft_putstr(larg);
		}
		else
		{
			ft_putstr(larg);
			form->type == 'C' || form->l == 1 ? ft_putwchar(c) : ft_putchar(c);
		}
	}
	else
		form->type == 'C' || form->l == 1 ? ft_putwchar(c) : ft_putchar(c);
	if (form->type == 'C' || form->l == 1)
		g_ret += ft_count_wchar(c);
	else
		g_ret += 1;
	g_ret += larg != NULL ? ft_strlen(larg) : 0;
}