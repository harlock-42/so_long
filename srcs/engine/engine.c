/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:12:16 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:12:58 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	paint_one_px(t_env *env, int y, int x)
{
	char			case_map;
	unsigned int	color;

	case_map = '\0';
	color = 0;
	case_map = wich_case_map(env, y, x);
	if (case_map == 'P')
		color = paint_player(env, y, x);
	else if (case_map == '1')
		color = color_sprite_px(x, y, env, WALL);
	else if (case_map == 'C')
		color = color_sprite_px(x, y, env, COLL);
	else if (case_map == 'E')
		color = color_sprite_px(x, y, env, EXIT);
	if (color != 0)
		my_mlx_pixel_put(env, x, y, color);
	else
	{
		color = color_sprite_px(x, y, env, FLOOR);
		my_mlx_pixel_put(env, x, y, color);
	}	
}

int	engine(t_env *env)
{
	int				x;
	int				y;
	unsigned int	color;
	char			case_map;

	x = 0;
	y = 0;
	move(env);
	case_map = '\0';
	while (x < env->data.width)
	{
		y = 0;
		while (y < env->data.height)
		{
			color = 0;
			paint_one_px(env, y, x);
			++y;
		}
		++x;
	}
	return (0);
}
