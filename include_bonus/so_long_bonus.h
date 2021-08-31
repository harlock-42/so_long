#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "./libft.h"
# include "./mlx_bonus.h"
# include "./color_bonus.h"
# include "./list_bonus.h"
# include "./struct_bonus.h"
# include "./keycode_bonus.h"

# define CHAR_MAP	"01CEP"
# define CASE_SIZE	64
# define SPEED		8

/*
** ENGINE
*/

char	wich_case_map(t_env *env, int y, int x);
int		calcul_move(t_env *env, int lock);
int		engine(t_env *env);
int		wich_case_px(int px);
unsigned int	color_px(t_env *env, int x, int y);
unsigned int	get_px_color_spawn_south(t_env *env, int x, int y);
unsigned int	get_px_color_spawn_west(t_env *env, int x, int y);
unsigned int	get_px_color_spawn_north(t_env *env, int x, int y);
unsigned int	get_px_color_spawn_east(t_env *env, int x, int y);
unsigned int	get_color_number(int x, int y, t_env *env, int nb);
void		new_image(t_env *env);
void		paint_moving_sprite(t_env *env);

/*
** KEY
*/

int	key_pressed(int keycode, t_env *env);
int	key_released(int keycode, t_env *env);
int	red_cross(int keycode, t_env *env);

/*
** LOAD_SPRITE
*/

int		load_sprite(t_env *env);

/*
** MOVE
*/

void	move(t_env *env);

/*
** PARSER
*/

char	**get_map(char *file_name);
int	check_map(char **map);
int	is_character_in_the_map(char **map);
int	is_map_closed(char **map);
int	is_map_rectangular(char **map);
int	parser(t_env *env, char *file_name);
void	get_map_size(t_env *env);

/*
** UTILS
*/

int	sl_error(char *str);
unsigned	int	color_sprite_px(int x, int y, t_env *env, int spr);
void	escape_game(t_env *env);
void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color);
void	print_map(char **map);

#endif
