#include "so_long.h"

static	int	is_only_one_player(char **map)
{
	int	play;
	int	j;
	int	i;

	play = 0;
	j = 0;
	while (map && map[j])
	{
		i = 0;
		while (map && map[j][i])
		{
			if (map[j][i] == 'P')
				++play;
			++i;
		}
		i = 0;
		++j;
	}
	if (play > 1)
		return (sl_error("the map must has only one player (P)"));
	else if (play == 0)
		return (sl_error("player (P) is missing in the map"));
	return (YES);
}

static	int	is_only_one_exit(char **map)
{
	int	exit;
	int	j;
	int	i;

	exit = 0;
	j = 0;
	while (map && map[j])
	{
		i = 0;
		while (map && map[j][i])
		{
			if (map[j][i] == 'E')
				++exit;
			++i;
		}
		i = 0;
		++j;
	}
	if (exit > 1)
		return (sl_error("the map must has only one exit (E)"));
	else if (exit == 0)
		return (sl_error("exit (E) is missing in the map"));
	return (YES);
}
static	int	there_is_collectible(char **map)
{
	int	col;
	int	j;
	int	i;

	col = 0;
	j = 0;
	while (map && map[j])
	{
		i = 0;
		while (map && map[j][i])
		{
			if (map[j][i] == 'C')
				++col;
			++i;
		}
		i = 0;
		++j;
	}
	if (col == 0)
		return (sl_error("collectible (C) are missing in the map"));
	return (YES);
}

int	is_character_in_the_map(char **map)
{
	if (is_only_one_player(map) == NO)
		return (NO);
	if (is_only_one_exit(map) == NO)
		return (NO);
	if (there_is_collectible(map) == NO)
		return (NO);
	return (YES);
}
