/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_number_sprite_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:06:53 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:08:48 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	wich_case_px(int px)
{
	int	case_map;
	int	count;

	case_map = CASE_SIZE;
	count = 0;
	while (case_map < px)
	{
		case_map += CASE_SIZE;
		++count;
	}
	return (count);
}

unsigned int	get_color_number(int x, int y, t_env *env, int nb)
{
	if (env->play.count > 99)
		return (color_sprite_px(x, y, env, NINE));
	if (nb == 0)
		return (color_sprite_px(x, y, env, ZERO));
	else if (nb == 1)
		return (color_sprite_px(x, y, env, ONE));
	else if (nb == 2)
		return (color_sprite_px(x, y, env, TWO));
	else if (nb == 3)
		return (color_sprite_px(x, y, env, THREE));
	else if (nb == 4)
		return (color_sprite_px(x, y, env, FOUR));
	else if (nb == 5)
		return (color_sprite_px(x, y, env, FIVE));
	else if (nb == 6)
		return (color_sprite_px(x, y, env, SIX));
	else if (nb == 7)
		return (color_sprite_px(x, y, env, SEVEN));
	else if (nb == 8)
		return (color_sprite_px(x, y, env, HEIGHT));
	else
		return (color_sprite_px(x, y, env, NINE));
}
