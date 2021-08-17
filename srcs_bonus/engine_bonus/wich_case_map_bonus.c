#include "so_long_bonus.h"

char	wich_case_map(t_env *env, int y, int x)
{
	int	j;
	int	i;
	int	px_y;
	int	px_x;

	j = 0;
	i = 0;
	px_y = CASE_SIZE;
	px_x = CASE_SIZE;
	while (px_y < y)
	{
		++j;
		px_y += CASE_SIZE;
	}
	while (px_x < x)
	{
		++i;
		px_x += CASE_SIZE;
	}
	return (env->data.map[j][i]);
}
