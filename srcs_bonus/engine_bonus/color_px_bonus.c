#include "so_long_bonus.h"

unsigned int	color_px(t_env *env, int x, int y)
{
	unsigned int	color;
	int	i;
	int	j;

	color = 0;
	i = x / CASE_SIZE;
	j = y / CASE_SIZE;
	if (env->data.map[j][i] == '1')
		color = 0X00FF0000;
	else if (env->data.map[j][i] == 'P')
		color = 0X0000FF00;
	else if (env->data.map[j][i] == 'C')
		color = 0X00FFFF00;
	else if (env->data.map[j][i] == 'E')
		color = 0X00FF00FF;
	return (color);
}
