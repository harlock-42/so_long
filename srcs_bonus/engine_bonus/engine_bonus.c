#include "so_long_bonus.h"

static	unsigned int	paint_floor(t_env *env, int x, int y)
{
	unsigned int	color;

	color = color_sprite_px(x, y, env, FLOOR);
	my_mlx_pixel_put(env, x, y, color);
	return (color);
}


static	unsigned int	paint_one_px(t_env *env, int y, int x)
{
	char		case_map;
	unsigned int	color;

	color = 0;
	case_map = '\0';
	case_map = wich_case_map(env, y, x);
	if (case_map == '1')
		color = color_sprite_px(x, y, env, WALL);
	else if (case_map == 'C')
		color = color_sprite_px(x, y, env, COLL);
	else if (case_map == 'E')
		color = color_sprite_px(x, y, env, EXIT);
	else
		color = 0;
	if (color != 0)
		my_mlx_pixel_put(env, x, y, color);
	return (color);
}

int	engine(t_env *env)
{
	unsigned int	color;
	int	x;
	int	y;

	y = 0;
	move(env);
	while (y < env->data.height)
	{
		x = 0;
		while (x < env->data.width)
		{
			color = 0;
			color = paint_floor(env, x, y);
			color = paint_one_px(env, y, x);
			color = paint_numbers_sprite(env, x, y);
			++x;
		}
		++y;
	}
	paint_moving_sprite(env);
	/*
	paint_numbers_sprite(env);
	*/
	return (0);
}
