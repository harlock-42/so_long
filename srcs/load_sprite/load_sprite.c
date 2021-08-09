#include "so_long.h"

static	void	sprite_cpy(t_env *env, int i)
{
	(void)i;
	int	j;
	int	end;

	j = 0;
	end = env->sprite.width[i] * env->sprite.height[i];
	while (j < end)
	{
		env->sprite.sprite[i][j] = env->sprite.ptr[i][j];
		++j;
	}
}

int	load_one_sprite(t_env *env, char *path_name, int i)
{
	env->sprite.img[i] = mlx_xpm_file_to_image(env->mlx.mlx,
		path_name, &env->sprite.width[i], &env->sprite.height[i]);
	if (env->sprite.img[i] == NULL)
	{
		ft_printf("%sError%s : ", RED, NC);
		ft_printf("%s doesn't load\n", path_name);
		return (-1);
	}
	env->sprite.ptr[i] = (unsigned int *)mlx_get_data_addr(env->sprite.img[i],
		&env->sprite.bpp[i], &env->sprite.line_length[i],
			&env->sprite.endian[i]);
	if (env->sprite.ptr[i] == NULL)
		return (-1);
	env->sprite.sprite[i] = ft_calloc(env->sprite.width[i]
		* env->sprite.height[i], sizeof(unsigned int));
	if (env->sprite.sprite[i] == NULL)
		return (-1);
	sprite_cpy(env, i);
	return (0);
}

int	load_sprite(t_env *env)
{
	int	i;

	i = 0;
	if (load_one_sprite(env, "./sprite/floor.xpm", i))
		return (-1);
	++i;
	if (load_one_sprite(env, "./sprite/wall.xpm", i))
		return (-1);
	++i;
	if (load_one_sprite(env, "./sprite/pokeball.xpm", i))
		return (-1);
	++i;
	if (load_one_sprite(env, "./sprite/exit.xpm", i))
		return (-1);
	++i;
	if (load_one_sprite(env, "./sprite/ash_down.xpm", i))
		return (-1);
	return (0);
}
