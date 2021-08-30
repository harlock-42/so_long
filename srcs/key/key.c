/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:25:56 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:25:58 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == KEY_W)
		env->move.up = 1;
	else if (keycode == KEY_A)
		env->move.left = 1;
	else if (keycode == KEY_D)
		env->move.right = 1;
	else if (keycode == KEY_S)
		env->move.down = 1;
	else if (keycode == KEY_ESC)
		escape_game(env);
	return (keycode);
}

int	key_released(int keycode, t_env *env)
{
	if (keycode == KEY_W)
		env->move.up = 0;
	else if (keycode == KEY_A)
		env->move.left = 0;
	else if (keycode == KEY_D)
		env->move.right = 0;
	else if (keycode == KEY_S)
		env->move.down = 0;
	return (keycode);
}

int	red_cross(int keycode, t_env *env)
{
	(void)env;
	exit(0);
	return (keycode);
}
