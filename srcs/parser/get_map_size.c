/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:30:01 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:30:03 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_size(t_env *env)
{
	int	j;

	j = 0;
	while (env->data.map && env->data.map[j])
		++j;
	env->data.height = j;
	env->data.width = (int)ft_strlen(env->data.map[0]);
}
