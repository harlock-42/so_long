#include "so_long.h"

static	char	wich_case_map(t_env *env, int y, int x)
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

static	unsigned	int	color_sprite_px(int x, int y, t_env *env, int spr)
{
	int	case_x;
	int	case_y;
	float	rat_x;
	float	rat_y;
	int	sprite_x;
	int	sprite_y;

	case_x = x % CASE_SIZE;
	case_y = y % CASE_SIZE;
	rat_x = (float)env->sprite.width[spr] / (float)CASE_SIZE;
	rat_y = (float)env->sprite.height[spr] / (float)CASE_SIZE;
	sprite_x = rat_x * case_x;
	sprite_y = rat_y * case_y;
	return (env->sprite.sprite[spr][sprite_y
		* env->sprite.line_length[spr] / 4 + sprite_x]);
}

static	void	paint_floor(t_env *env)
{
	int		x;
	int		y;
	unsigned int	color;

	x = 0;
	y = 0;
	color = 0;
	while (y < env->data.height)
	{
		x = 0;
		while (x < env->data.width)
		{
			color = color_sprite_px(x, y, env, FLOOR);
			my_mlx_pixel_put(env, x, y, color);
			++x;
		}
		++y;
	}
}

static	void	paint_one_px(t_env *env, int y, int x)
{
	char		case_map;
	unsigned int	color;

	case_map = '\0';
	color = 0;
	case_map = wich_case_map(env, y, x);
	if (case_map == 'P')
		color = color_sprite_px(x, y, env, P_DOWN);
	else if (case_map == '1')
		color = color_sprite_px(x, y, env, WALL);
	else if (case_map == 'C')
		color = color_sprite_px(x, y, env, COLL);
	else if (case_map == 'E')
		color = color_sprite_px(x, y, env, EXIT);
	if (color != 0)
		my_mlx_pixel_put(env, x, y, color);
}

int	engine(t_env *env)
{
	int		x;
	int		y;
	unsigned int	color;
	char		case_map;

	x = 0;
	y = 0;
	move(env);
	case_map = '\0';
	paint_floor(env);
	while (x < env->data.width)
	{
		y = 0;
		while (y < env->data.height)
		{
			color = 0;
			paint_one_px(env, y, x);
			++y;
		}
		++x;
	}
	return (0);
}
