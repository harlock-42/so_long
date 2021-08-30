/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:57:47 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:58:00 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = env->img.ptr + (y * env->data.width + x);
	*(unsigned int *)dst = color;
}
