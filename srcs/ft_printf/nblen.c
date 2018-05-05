#include "ft_printf.h"

int		nblen(intmax_t nb)
{
	int		i;

	i = 1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
