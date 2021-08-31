/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:00:58 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:01:36 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	is_case_number(t_env *env, int x, int y)
{
	int	end_map;
	int	case_x;

	case_x = wich_case_px(x);
	end_map = wich_case_px(env->data.width);
	if (wich_case_px(y) == 0 && (case_x == end_map))
		return (YES);
	if (env->play.count > 9 && wich_case_px(y) == 0 && case_x == end_map - 1)
		return (YES);
	return (NO);
}

static	unsigned int	get_number_color(int x, int y, t_env *env)
{
	int	end_map;
	int	case_x;

	case_x = wich_case_px(x);
	end_map = wich_case_px(env->data.width);
	if (wich_case_px(y) == 0 && (case_x == end_map))
		return (get_color_number(x, y, env, env->play.count % 10));
	if (env->play.count > 9 && wich_case_px(y) == 0 && case_x == end_map - 1)
		return (get_color_number(x, y, env, env->play.count / 10));
	return (0);
}

static	unsigned int	paint_one_px(t_env *env, int y, int x)
{
	char			case_map;
	unsigned int	color;

	color = 0;
	case_map = '\0';
	case_map = wich_case_map(env, y, x);
	if (is_case_number(env, x, y) == YES)
		color = get_number_color(x, y, env);
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
	return (color);
}

int	engine(t_env *env)
{
	unsigned int	color;
	int				x;
	int				y;

	y = 0;
	move(env);
	while (y < env->data.height)
	{
		x = 0;
		while (x < env->data.width)
		{
			color = paint_one_px(env, y, x);
			++x;
		}
		++y;
	}
	paint_moving_sprite(env);
	return (0);
}
