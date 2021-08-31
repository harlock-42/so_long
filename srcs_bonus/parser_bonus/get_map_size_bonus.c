/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:14:31 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:14:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
static int	get_sqrt_round()
{

}
*/
void	get_map_size(t_env *env)
{
	int	j;

	j = 0;
	while (env->data.map && env->data.map[j])
		++j;
	env->data.height = j;
	env->data.width = (int)ft_strlen(env->data.map[0]);
	env->play.speed = (env->data.width * env->data.height) / 8;
	ft_printf("%d\n", env->play.speed);
}
