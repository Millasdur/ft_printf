#include "ft_printf.h"

char		*ft_percent(va_list *arg, t_opt *opt)
{
	char	*res;

	(void)arg;
	res = ft_strdup("%");
	opt->preci = -1;
	res = handle_strflag(res, *opt);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
