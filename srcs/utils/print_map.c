#include "so_long.h"

static	void	print_color(char c)
{
	if (c == '1')
		ft_printf("%s%c%s", PURPLE, c, NC);
	else if (c == '0')
		ft_printf("%s%c%s", BLACK, c, NC);
	else if (c == 'E')
		ft_printf("%s%c%s", YELLOW, c, NC);
	else if (c == 'P')
		ft_printf("%s%c%s", YELLOW, c, NC);
	else if (c == 'C')
		ft_printf("%s%c%s", GREEN, c, NC);
	else
		ft_printf("%s%c%s", RED, c, NC);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	if (map == NULL)
	{
		ft_printf("map is empty :(\n");
		return ;
	}
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			print_color(map[j][i]);
			++i;
		}
		ft_printf("\n");
		++j;
	}
}
