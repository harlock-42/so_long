#include "so_long.h"

int	sl_error(char *str)
{
	ft_printf("%sError%s : ", RED, NC);
	ft_printf("%s\n", str);
	return (-1);
}
