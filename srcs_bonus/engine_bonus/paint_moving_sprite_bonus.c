#include "so_long_bonus.h"

static	unsigned int	paint_player(t_env *env, int y, int x)
{
	char	case_map;
	unsigned int	color;

	case_map = wich_case_map(env, y, x);
	color = 0;
	if (case_map == 'P')
	{
		if (env->play.spawn == 2)
			color = get_px_color_spawn_south(env, x, y);
		if (env->play.spawn == 0)
			color = get_px_color_spawn_north(env, x, y);
		if (env->play.spawn == 1)
			color = get_px_color_spawn_east(env, x, y);
		if (env->play.spawn == 3)
			color = get_px_color_spawn_west(env, x, y);
		if (color != 0)
			my_mlx_pixel_put(env, x + env->play.move_x,
				y + env->play.move_y, color);
	}
	return (color);
}

void	paint_moving_sprite(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < env->data.width)
	{
		y = 0;
		while (y < env->data.height)
		{
			paint_player(env, y, x);
			++y;
		}
		++x;
	}
	env->move.lock = calcul_move(env, env->move.lock);
}
