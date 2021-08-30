/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_px.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:11:32 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:11:54 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	color_px(t_env *env, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	color = 0;
	i = x / CASE_SIZE;
	j = y / CASE_SIZE;
	if (env->data.map[j][i] == '1')
		color = 0X00FF0000;
	else if (env->data.map[j][i] == 'P')
		color = 0X0000FF00;
	else if (env->data.map[j][i] == 'C')
		color = 0X00FFFF00;
	else if (env->data.map[j][i] == 'E')
		color = 0X00FF00FF;
	return (color);
}
