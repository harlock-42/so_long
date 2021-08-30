/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:22:06 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:22:15 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = env->img.ptr + (y * env->data.width + x);
	*(unsigned int *)dst = color;
}
