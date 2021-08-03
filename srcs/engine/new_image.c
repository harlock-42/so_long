#include "so_long.h"

void	new_image(t_env *env)
{
	if (!(env->img.img = mlx_new_image(env->mlx.mlx, env->data.width,
	env->data.height)))
	{
		ft_printf("Error\nGenerating new image failed\n");
		exit(1);
	}
	env->img.ptr = (unsigned int *)mlx_get_data_addr(env->img.img,
	&env->img.bpp, &env->img.line_length, &env->img.endian);
}

