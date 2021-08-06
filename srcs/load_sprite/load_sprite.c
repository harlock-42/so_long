#include "so_long.h"

static	void	sprite_cpy(t_env *env, int i)
{
	(void)i;
	int	j;
	int	end;

	j = 0;
	end = env->sprite.width * env->sprite.height;
	while (j < end)
	{
		env->sprite.sprite[j] = env->sprite.ptr[j];
		++j;
	}
}

int	load_one_sprite(t_env *env, char *path_name, int i)
{
	(void)i;

	env->sprite.img = mlx_xpm_file_to_image(env->mlx.mlx,
		path_name, &env->sprite.width, &env->sprite.height);
	if (env->sprite.img == NULL)
		return (-1);
	env->sprite.ptr = (unsigned int *)mlx_get_data_addr(env->sprite.img,
		&env->sprite.bpp, &env->sprite.line_length,
			&env->sprite.endian);
	if (env->sprite.ptr == NULL)
		return (-1);
	env->sprite.sprite = ft_calloc(env->sprite.width * env->sprite.height,
		sizeof(unsigned int));
	if (env->sprite.sprite == NULL)
		return (-1);
	sprite_cpy(env, i);
	return (0);
}

int	load_sprite(t_env *env)
{
	int	i;

	i = 0;
	if (load_one_sprite(env, "./sprite/floor_pkn.xpm", i))
		return (-1);
	return (0);
}
