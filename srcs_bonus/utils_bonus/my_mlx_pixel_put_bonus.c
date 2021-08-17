#include "so_long_bonus.h"

void		my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = env->img.ptr + (y * env->data.width + x);
	*(unsigned int *)dst = color;
}
