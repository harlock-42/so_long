#include "so_long.h"

static	void	get_player_pos(t_env *env, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map && map[y][x])
		{
			if (map[y][x] == 'P')
			{
				env->play.pos_x = x;
				env->play.pos_y = y;
			}
			++x;
		}
		++y;
	}
}

static	void	get_number_coll(t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (env->data.map && env->data.map[y])
	{
		x = 0;
		while (env->data.map && env->data.map[y][x])
		{
			if (env->data.map[y][x] == 'C')
				++env->data.nb_coll;
			++x;
		}
		++y;
	}
}

static	void	get_data_map(t_env *env)
{
	get_number_coll(env);
	get_map_size(env);
	get_player_pos(env, env->data.map);
}

static	int	check_file_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	if (i < 5)
		return (-1);
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
		return (-1);
	return (0);
}

int	parser(t_env *env, char *file_name)
{
	if (check_file_name(file_name))
		return (sl_error("map file is not a \".ber\" extention"));
	env->data.map = get_map(file_name);
	if (env->data.map == NULL)
		return (-1);
	if (check_map(env->data.map))
	{
		free_tab(env->data.map);
		return (-1);
	}
	get_data_map(env);
	return (0);
}
