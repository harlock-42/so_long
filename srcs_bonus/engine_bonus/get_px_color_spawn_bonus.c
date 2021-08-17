#include "so_long_bonus.h"

static	int	convert_move_in_per_cent(int move)
{
	int	nb;

	if (move < 1)
		move *= (-1);
	nb = (move * 100) / CASE_SIZE;
	return (nb);
}

unsigned int	get_px_color_spawn_south(t_env *env, int x, int y)
{
	int	ind_move;
	unsigned int	color;

	ind_move = convert_move_in_per_cent(env->play.move_y);
	if (ind_move == 0)
		color = color_sprite_px(x, y, env, P_DOWN_0);
	else if (ind_move > 10 && ind_move < 45)
		color = color_sprite_px(x, y, env, P_DOWN_1);
	else if (ind_move > 55 && ind_move < 90)
		color = color_sprite_px(x, y, env, P_DOWN_2);
	else
		color = color_sprite_px(x, y, env, P_DOWN_0);
	return (color);
}

unsigned int	get_px_color_spawn_west(t_env *env, int x, int y)
{
	int	ind_move;
	unsigned int	color;

	ind_move = convert_move_in_per_cent(env->play.move_x);
	if (ind_move == 0)
		color = color_sprite_px(x, y, env, P_LEFT_0);
	else if (ind_move > 10 && ind_move < 45)
		color = color_sprite_px(x, y, env, P_LEFT_1);
	else if (ind_move > 55 && ind_move < 90)
		color = color_sprite_px(x, y, env, P_LEFT_2);
	else
		color = color_sprite_px(x, y, env, P_LEFT_0);
	return (color);
}

unsigned int	get_px_color_spawn_north(t_env *env, int x, int y)
{
	int	ind_move;
	unsigned int	color;

	ind_move = convert_move_in_per_cent(env->play.move_y);
	if (ind_move == 0)
		color = color_sprite_px(x, y, env, P_UP_0);
	else if (ind_move > 10 && ind_move < 45)
		color = color_sprite_px(x, y, env, P_UP_1);
	else if (ind_move > 55 && ind_move < 90)
		color = color_sprite_px(x, y, env, P_UP_2);
	else
		color = color_sprite_px(x, y, env, P_UP_0);
	return (color);
}

unsigned int	get_px_color_spawn_east(t_env *env, int x, int y)
{
	int	ind_move;
	unsigned int	color;

	ind_move = convert_move_in_per_cent(env->play.move_x);
	if (ind_move == 0)
		color = color_sprite_px(x, y, env, P_RIGHT_0);
	else if (ind_move > 10 && ind_move < 45)
		color = color_sprite_px(x, y, env, P_RIGHT_1);
	else if (ind_move > 55 && ind_move < 90)
		color = color_sprite_px(x, y, env, P_RIGHT_2);
	else
		color = color_sprite_px(x, y, env, P_RIGHT_0);
	return (color);
}

