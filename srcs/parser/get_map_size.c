#include "so_long.h"

void	get_map_size(t_env *env)
{
	int	j;

	j = 0;
	while (env->data.map && env->data.map[j])
		++j;
	env->data.height = j;
	env->data.width = (int)ft_strlen(env->data.map[0]);
}
