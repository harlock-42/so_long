/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:26:43 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/31 18:21:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	sprite_cpy(t_env *env, int i)
{
	int	j;
	int	end;

	j = 0;
	end = env->sprite.width[i] * env->sprite.height[i];
	while (j < end)
	{
		env->sprite.sprite[i][j] = env->sprite.ptr[i][j];
		++j;
	}
}

int	load_one_sprite(t_env *env, char *path_name, int i)
{
	env->sprite.img[i] = mlx_xpm_file_to_image(env->mlx.mlx,
			path_name, &env->sprite.width[i], &env->sprite.height[i]);
	if (env->sprite.img[i] == NULL)
	{
		ft_printf("%sError%s : ", RED, NC);
		ft_printf("%s doesn't load\n", path_name);
		return (-1);
	}
	env->sprite.ptr[i] = (unsigned int *)mlx_get_data_addr(env->sprite.img[i],
			&env->sprite.bpp[i], &env->sprite.line_length[i],
			&env->sprite.endian[i]);
	if (env->sprite.ptr[i] == NULL)
		return (-1);
	env->sprite.sprite[i] = ft_calloc(env->sprite.width[i]
			* env->sprite.height[i], sizeof(unsigned int));
	if (env->sprite.sprite[i] == NULL)
		return (-1);
	sprite_cpy(env, i);
	return (0);
}

static	char	**get_all_the_path_name(char **str)
{
	str[FLOOR] = ft_strdup("./sprite/floor.xpm");
	str[WALL] = ft_strdup("./sprite/wall.xpm");
	str[COLL] = ft_strdup("./sprite/pokeball.xpm");
	str[EXIT] = ft_strdup("./sprite/exit.xpm");
	str[P_DOWN_0] = ft_strdup("./sprite/ash_down_0.xpm");
	str[P_DOWN_1] = ft_strdup("./sprite/ash_down_1.xpm");
	str[P_DOWN_2] = ft_strdup("./sprite/ash_down_2.xpm");
	str[P_LEFT_0] = ft_strdup("./sprite/ash_left_0.xpm");
	str[P_LEFT_1] = ft_strdup("./sprite/ash_left_1.xpm");
	str[P_LEFT_2] = ft_strdup("./sprite/ash_left_2.xpm");
	str[P_UP_0] = ft_strdup("./sprite/ash_up_0.xpm");
	str[P_UP_1] = ft_strdup("./sprite/ash_up_1.xpm");
	str[P_UP_2] = ft_strdup("./sprite/ash_up_2.xpm");
	str[P_RIGHT_0] = ft_strdup("./sprite/ash_right_0.xpm");
	str[P_RIGHT_1] = ft_strdup("./sprite/ash_right_1.xpm");
	str[P_RIGHT_2] = ft_strdup("./sprite/ash_right_2.xpm");
	return (str);
}

static	char	**get_path_name(char **path_name)
{
	path_name = (char **)malloc((sizeof(char *) * NB_SPRITE) + 1);
	if (path_name == NULL)
		return (NULL);
	path_name = get_all_the_path_name(path_name);
	return (path_name);
}

int	load_sprite(t_env *env)
{
	char	**path_name;
	int		i;

	ft_bzero(&path_name, sizeof(char **));
	path_name = get_path_name(path_name);
	if (path_name == NULL)
		return (sl_error("memory space is not enough to load sprites"));
	i = 0;
	while (i < NB_SPRITE)
	{
		if (path_name[i] == NULL)
		{
			ft_printf("%sError%s : \n", RED, NC);
			ft_printf("%s doesn't load\n", path_name);
			ft_printf("%d\n", i);
			return (-1);
		}
		if (load_one_sprite(env, path_name[i], i))
			return (-1);
		++i;
	}
	path_name = (char **)free_tab(path_name);
	return (0);
}
