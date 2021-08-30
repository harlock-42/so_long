/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:21:53 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:21:54 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	free(env->data.map);
	free(env->mlx.mlx);
	exit(0);
}
