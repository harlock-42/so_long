#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include "./libft.h"
# include "./mlx.h"
# include "./color.h"
# include "./list.h"
# include "./struct.h"
# include "./keycode.h"

# define CHAR_MAP	"01CEP"
# define CASE_SIZE	64

/*
** ENGINE
*/

int		engine(t_env *env);
unsigned int	color_px(t_env *env, int x, int y);
void		new_image(t_env *env);

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
void	escape_game(t_env *env);
void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color);
void	print_map(char **map);

#endif
