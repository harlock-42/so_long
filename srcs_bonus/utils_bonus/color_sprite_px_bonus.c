#include "so_long_bonus.h"

unsigned	int	color_sprite_px(int x, int y, t_env *env, int spr)
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
