/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:57:17 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:57:18 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	escape_game(t_env *env)
{
	int	i;

	i = 0;
	mlx_destroy_image(env->mlx.mlx, env->img.img);
	while (i < NB_SPRITE)
	{
		mlx_destroy_image(env->mlx.mlx, env->sprite.img[i]);
		free(env->sprite.sprite[i]);
		++i;
	}
	i = 0;
	while (env->data.map && env->data.map[i])
	{
		free(env->data.map[i]);
		++i;
	}
	mlx_destroy_window(env->mlx.mlx, env->mlx.win);
	free(env->data.map);
	free(env->mlx.mlx);
	exit(0);
}
