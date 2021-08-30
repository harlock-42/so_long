#include "so_long.h"

static	int	are_char_in_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (c_is_str(map[j][i], CHAR_MAP) == NO)
			{
				ft_printf("%sError%s\n", RED, NC);
				ft_printf("line %d, char %d\n", j, i);
				ft_printf("invalid charactere (\'%c\')", map[j][i]);
				ft_printf(" in the map\n");
				return (NO);
			}
			++i;
		}
		i = 0;
		++j;
	}
	return (YES);
}

int	check_map(char **map)
{
	if (are_char_in_map_valid(map) == NO)
		return (-1);
	if (is_map_rectangular(map) == NO)
		return (sl_error("map is not rectangular"));
	if (is_map_closed(map) == NO)
		return (sl_error("map is not closed"));
	if (is_character_in_the_map(map) == NO)
		return (-1);
	return (0);
}
