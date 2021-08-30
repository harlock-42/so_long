#include "so_long.h"

int	sl_error(char *str)
{
	ft_printf("%sError%s\n", RED, NC);
	ft_printf("%s\n", str);
	return (-1);
}
