#include "so_long.h"

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
	if (check_map(env->data.map))
	{
		free_tab(env->data.map);
		return (-1);
	}
	get_map_size(env);
	return (0);
}
