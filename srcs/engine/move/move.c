/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:24:36 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:25:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	go_right(t_env *env)
{
	env->data.prev_case
		= env->data.map[env->play.pos_y][env->play.pos_x + 1];
	env->play.spawn = 1;
	if (env->data.map[env->play.pos_y][env->play.pos_x + 1] == '1'
		|| (env->data.map[env->play.pos_y][env->play.pos_x + 1] == 'E'
			&& env->data.nb_coll > 0))
		return ;
	if (env->data.map[env->play.pos_y][env->play.pos_x + 1] == 'E')
		escape_game(env);
	if (env->data.map[env->play.pos_y][env->play.pos_x + 1] == 'C')
		--env->data.nb_coll;
	env->data.map[env->play.pos_y][env->play.pos_x + 1] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	++env->play.pos_x;
	env->move.right = 0;
	++env->play.count;
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
	if (env->data.map[env->play.pos_y][env->play.pos_x - 1] == 'E')
		escape_game(env);
	if (env->data.map[env->play.pos_y][env->play.pos_x - 1] == 'C')
		--env->data.nb_coll;
	env->data.map[env->play.pos_y][env->play.pos_x - 1] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	--env->play.pos_x;
	env->move.left = 0;
	++env->play.count;
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
	if (env->data.map[env->play.pos_y - 1][env->play.pos_x] == 'E')
		escape_game(env);
	if (env->data.map[env->play.pos_y - 1][env->play.pos_x] == 'C')
		--env->data.nb_coll;
	env->data.map[env->play.pos_y - 1][env->play.pos_x] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	--env->play.pos_y;
	env->move.up = 0;
	++env->play.count;
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
	if (env->data.map[env->play.pos_y + 1][env->play.pos_x] == 'C')
		--env->data.nb_coll;
	if (env->data.map[env->play.pos_y + 1][env->play.pos_x] == 'E')
		escape_game(env);
	env->data.map[env->play.pos_y + 1][env->play.pos_x] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	++env->play.pos_y;
	env->move.down = 0;
	++env->play.count;
	ft_printf("%d\n", env->play.count);
}

void	move(t_env *env)
{
	if (env->move.down == 1)
		go_down(env);
	if (env->move.up == 1)
		go_up(env);
	if (env->move.left == 1)
		go_left(env);
	if (env->move.right == 1)
		go_right(env);
}
