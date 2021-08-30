/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:00:05 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:00:16 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	game(t_env *env)
{
	if (env->img.img != NULL)
		mlx_destroy_image(env->mlx.mlx, env->img.img);
	new_image(env);
	engine(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->img.img, 0, 0);
	return (0);
}

static	void	start_game(t_env *env)
{
	env->mlx.mlx = mlx_init();
	if (load_sprite(env))
		return ;
	env->data.width *= CASE_SIZE;
	env->data.height *= CASE_SIZE;
	env->mlx.win = mlx_new_window(env->mlx.mlx, env->data.width,
			env->data.height, "so_long");
	mlx_hook(env->mlx.win, 2, 1L << 0, key_pressed, env);
	mlx_hook(env->mlx.win, 3, 1L << 1, key_released, env);
	mlx_hook(env->mlx.win, 17, 1L << 17, red_cross, env);
	mlx_loop_hook(env->mlx.mlx, game, env);
	mlx_loop(env->mlx.mlx);
}

static	void	init_env(t_env *env)
{
	ft_bzero(&env->data, sizeof(env->data));
	ft_bzero(&env->img, sizeof(env->img));
	ft_bzero(&env->move, sizeof(env->move));
	ft_bzero(&env->play, sizeof(env->play));
	ft_bzero(&env->mlx, sizeof(env->mlx));
	env->play.spawn = 2;
}

int	main(int argc, char **argv)
{
	t_env	env;

	ft_bzero(&env, sizeof(env));
	init_env(&env);
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
