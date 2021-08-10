#include "so_long.h"

static	void	move_player(t_env *env, int spawn)
{
	if (spawn == EAST)
		++env->play.move_x;
	else if (spawn == WEST)
		--env->play.move_x;
	else if (spawn == SOUTH)
		++env->play.move_y;
	else if (spawn == NORTH)
		--env->play.move_y;
}

static	void	write_new_pos_play_in_map(t_env *env, int spawn)
{
	if (spawn == EAST)
	{
		env->data.map[env->play.pos_y][env->play.pos_x + 1] = 'P';
		env->data.map[env->play.pos_y][env->play.pos_x] = '0';
		++env->play.pos_x;
	}
	else if (spawn == WEST)
	{
		env->data.map[env->play.pos_y][env->play.pos_x - 1] = 'P';
		env->data.map[env->play.pos_y][env->play.pos_x] = '0';
		--env->play.pos_x;
	}
	else if (spawn == SOUTH)
	{
		env->data.map[env->play.pos_y + 1][env->play.pos_x] = 'P';
		env->data.map[env->play.pos_y][env->play.pos_x] = '0';
		++env->play.pos_y;
	}
	else if (spawn == NORTH)
	{
		env->data.map[env->play.pos_y - 1][env->play.pos_x] = 'P';
		env->data.map[env->play.pos_y][env->play.pos_x] = '0';
		--env->play.pos_y;
	}

}

static	int	is_move_finished(t_env *env)
{
	int	y;
	int	x;

	if (env->play.move_x < 0)
		x = env->play.move_x * (-1);
	else
		x = env->play.move_x;
	if (env->play.move_y < 0)
		y = env->play.move_y * (-1);
	else
		y = env->play.move_y;
	if (x == CASE_SIZE || y == CASE_SIZE)
		return (YES);
	return (NO);
}

int	calcul_move(t_env *env, int lock)
{
	if (lock == 0)
		return (0);
	if (is_move_finished(env) == YES)
	{
		write_new_pos_play_in_map(env, env->play.spawn);
		if (env->play.spawn == WEST || env->play.spawn == EAST)
			env->play.move_x = 0;
		else
			env->play.move_y = 0;
		return (0);
	}
	move_player(env, env->play.spawn);
	return (1);
}
