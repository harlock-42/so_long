#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
}		t_mlx;

typedef	struct	s_data
{
	char	**map;
	int	height;
	int	width;
	int	pos_play_x;
	int	pos_play_y;
}		t_data;

typedef	struct	s_img
{
	unsigned int	*ptr;
	void		*img;
	int		line_length;
	int		bpp;
	int		endian;
	int		color;
}		t_img;

typedef	struct	s_sprite
{
	char		*path_name;
	unsigned int	*ptr;
	unsigned int	*img;
	unsigned int	*sprite;
	int		line_length;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}		t_sprite;

typedef	struct	s_env
{
	t_data		data;
	t_img		img;
	t_mlx		mlx;
	t_sprite	sprite;
}		t_env;

#endif
