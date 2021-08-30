/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:22:15 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_image(t_env *env)
{
	env->img.img = mlx_new_image(env->mlx.mlx, env->data.width,
			env->data.height);
	if (env->img.img == NULL)
	{
		ft_printf("Error\nGenerating new image failed\n");
		exit(1);
	}
	env->img.ptr = (unsigned int *)mlx_get_data_addr(env->img.img,
			&env->img.bpp, &env->img.line_length, &env->img.endian);
}
