#include "so_long.h"

static	void	go_right(t_env *env)
{
	if (env->data.map[env->play.pos_y][env->play.pos_x + 1] == '1')
		return ;
	env->data.map[env->play.pos_y][env->play.pos_x + 1] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	++env->play.pos_x;
	env->move.right = 0;
	++env->play.count;
	ft_printf("%d\n", env->play.count);
}

static	void	go_left(t_env *env)
{
	if (env->data.map[env->play.pos_y][env->play.pos_x - 1] == '1')
		return ;
	env->data.map[env->play.pos_y][env->play.pos_x - 1] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	--env->play.pos_x;
	env->move.left = 0;
	++env->play.count;
	ft_printf("%d\n", env->play.count);
}

static	void	go_up(t_env *env)
{
	if (env->data.map[env->play.pos_y - 1][env->play.pos_x] == '1')
		return ;
	env->data.map[env->play.pos_y - 1][env->play.pos_x] = 'P';
	env->data.map[env->play.pos_y][env->play.pos_x] = '0';
	--env->play.pos_y;
	env->move.up = 0;
	++env->play.count;
	ft_printf("%d\n", env->play.count);
}

static	void	go_down(t_env *env)
{
	if (env->data.map[env->play.pos_y + 1][env->play.pos_x] == '1')
		return ;
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
