#include "so_long.h"

static	void	start_game(t_env *env)
{
	env->mlx.mlx = mlx_init();
	env->data.width *= CASE_SIZE;
	env->data.height *= CASE_SIZE;
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->data.width,
		env->data.height, "so_long");
	new_image(env);
	engine(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->img.img, 0, 0);
	mlx_loop(env->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	if (argc != 2)
	{
		sl_error("wrong number of argyuments");
		return (0);
	}
	if (parser(&env, argv[1]))
		return (0);
	
	start_game(&env);
	return (0);
}
