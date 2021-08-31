/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_moving_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:22:47 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:23:30 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	paint_player(t_env *env, int y, int x)
{
	char			case_map;
	unsigned int	color;

	case_map = wich_case_map(env, y, x);
	color = 0;
	if (env->play.spawn == 2)
		color = get_px_color_spawn_south(env, x, y);
	if (env->play.spawn == 0)
		color = get_px_color_spawn_north(env, x, y);
	if (env->play.spawn == 1)
		color = get_px_color_spawn_east(env, x, y);
	if (env->play.spawn == 3)
		color = get_px_color_spawn_west(env, x, y);
	return (color);
}
