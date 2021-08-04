#include "so_long.h"

int	engine(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < env->data.width)
	{
		y = 0;
		while (y < env->data.height)
		{
			my_mlx_pixel_put(env, x, y, color_px(env, x, y));
			++y;
		}
		++x;
	}
	return (0);
}
