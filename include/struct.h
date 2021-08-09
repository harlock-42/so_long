#ifndef STRUCT_H
# define STRUCT_H

enum		e_sprite
{
	FLOOR = 0,
	WALL,
	COLL,
	EXIT,
	P_DOWN,
	NB_SPRITE
};

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
	int	nb_coll;
	char	prev_case;
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
	unsigned int	*ptr[NB_SPRITE];
	unsigned int	*img[NB_SPRITE];
	unsigned int	*sprite[NB_SPRITE];
	int		line_length[NB_SPRITE];
	int		bpp[NB_SPRITE];
	int		endian[NB_SPRITE];
	int		width[NB_SPRITE];
	int		height[NB_SPRITE];
}		t_sprite;

typedef	struct	s_move
{
	int	up;
	int	down;
	int	right;
	int	left;
}		t_move;

typedef	struct	s_play
{
	int	pos_x;
	int	pos_y;
	int	count;
}		t_play;

typedef	struct	s_env
{
	t_data		data;
	t_img		img;
	t_mlx		mlx;
	t_sprite	sprite;
	t_move		move;
	t_play		play;
}		t_env;

#endif
