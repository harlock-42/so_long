#include "so_long.h"

static	unsigned	int	color_sprite_px(int x, int y, t_env *env)
{
	int	case_x;
	int	case_y;
	float	rat_x;
	float	rat_y;
	int	sprite_x;
	int	sprite_y;
	int	px;

	case_x = x % CASE_SIZE;
	case_y = y % CASE_SIZE;
	rat_x = (float)env->sprite.width / (float)CASE_SIZE;
	rat_y = (float)env->sprite.height / (float)CASE_SIZE;
	sprite_x = rat_x * case_x;
	sprite_y = rat_y * case_y;
	printf("%d\n", sprite_y);
	px = env->sprite.sprite[sprite_y * env->sprite.line_length + x];
//	ft_printf("%d\n", px);
	return (env->sprite.sprite[sprite_y * env->sprite.line_length + sprite_x]);
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
//			ft_printf("%d %d\n", y, x);
			color = color_sprite_px(x, y, env);
			my_mlx_pixel_put(env, x, y, color);
			++x;
		}
		++y;
	}
}

int	engine(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	paint_floor(env);
	while (x < env->data.width)
	{
		y = 0;
		while (y < env->data.height)
		{
//			my_mlx_pixel_put(env, x, y, color_px(env, x, y));
			++y;
		}
		++x;
	}
	return (0);
}
