#include "so_long.h"

unsigned int	color_player_px(int x, int y, t_env *env)
{
	unsigned int	color;

	color = 0;
	if (env->play.spawn == 2)
		color = get_px_color_spawn_south(env, x , y);
	if (env->play.spawn == 0)
		color = get_px_color_spawn_north(env, x, y);
	if (env->play.spawn == 1)
		color = get_px_color_spawn_east(env, x, y);
	if (env->play.spawn == 3)
		color = get_px_color_spawn_west(env, x, y);
	return (color);
}
