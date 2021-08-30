/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:09:27 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:11:00 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	go_right(t_env *env)
{
	env->data.prev_case
		= env->data.map[env->play.pos_y][env->play.pos_x + 1];
	env->play.spawn = 1;
	if (env->data.map[env->play.pos_y][env->play.pos_x + 1] == '1'
		|| (env->data.map[env->play.pos_y][env->play.pos_x + 1] == 'E'
			&& env->data.nb_coll > 0))
		return ;
	env->move.right = 0;
	++env->play.count;
	env->move.lock = 1;
	ft_printf("%d\n", env->play.count);
}

static	void	go_left(t_env *env)
{
	env->data.prev_case
		= env->data.map[env->play.pos_y][env->play.pos_x - 1];
	env->play.spawn = 3;
	if (env->data.map[env->play.pos_y][env->play.pos_x - 1] == '1'
		|| (env->data.map[env->play.pos_y][env->play.pos_x - 1] == 'E'
			&& env->data.nb_coll > 0))
		return ;
	env->move.left = 0;
	++env->play.count;
	env->move.lock = 1;
	ft_printf("%d\n", env->play.count);
}

static	void	go_up(t_env *env)
{
	env->data.prev_case
		= env->data.map[env->play.pos_y - 1][env->play.pos_x];
	env->play.spawn = 0;
	if (env->data.map[env->play.pos_y - 1][env->play.pos_x] == '1'
		|| (env->data.map[env->play.pos_y - 1][env->play.pos_x] == 'E'
			&& env->data.nb_coll > 0))
		return ;
	env->move.up = 0;
	++env->play.count;
	env->move.lock = 1;
	ft_printf("%d\n", env->play.count);
}

static	void	go_down(t_env *env)
{
	env->data.prev_case
		= env->data.map[env->play.pos_y + 1][env->play.pos_x];
	env->play.spawn = 2;
	if (env->data.map[env->play.pos_y + 1][env->play.pos_x] == '1'
		|| (env->data.map[env->play.pos_y + 1][env->play.pos_x] == 'E'
			&& env->data.nb_coll > 0))
		return ;
	env->move.down = 0;
	++env->play.count;
	env->move.lock = 1;
	ft_printf("%d\n", env->play.count);
}

void	move(t_env *env)
{
	if (env->move.lock)
		return ;
	if (env->move.down == 1)
		go_down(env);
	if (env->move.up == 1)
		go_up(env);
	if (env->move.left == 1)
		go_left(env);
	if (env->move.right == 1)
		go_right(env);
}
