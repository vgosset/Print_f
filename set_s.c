#include "ft_printf.h"

char	*set_s(t_struct *strct, va_list ap)
{
	char	*str;
	char	*larg;

	str = va_arg(ap, char *);
	if (strct->prec < ft_strlen(str))
		str = ft_strsub(str, 0, strct->prec);
	if (strct->larg != 0)
		larg = set_larg(strct, str);
	if (strct->prec == 0)
		str = larg;
	else if (strct->moins == 1)
		str = ft_strjoin(str, larg);
	else
		str = ft_strjoin(larg, str);
	return (str);
}

char *set_larg(t_struct *strct, char *larg)
{
	if (strct->larg > 0)
	{
		if (strct->prec >= 0)
		{
			if (strct->larg > strct->prec)
			{
				larg = ft_strnew(strct->larg - strct->prec);
				larg = strplace_s(strct, strct->larg - strct->prec, ' ');
			}
		}
		else
		{
			if (strct->larg > ft_strlen(larg))
			{
				larg = ft_strnew(strct->larg - ft_strlen(larg));
				larg = strplace_s(strct, strct->larg - ft_strlen(larg), ' ');
			}
		}
	}
	return (larg);
}
