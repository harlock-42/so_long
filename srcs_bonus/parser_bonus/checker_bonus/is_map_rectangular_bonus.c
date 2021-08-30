/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_rectangular_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:16:44 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:16:45 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_map_rectangular(char **map)
{
	int	i;
	int	size_prev;
	int	size;

	size_prev = 0;
	size = 0;
	i = 0;
	size = ft_strlen(map[i]);
	while (map[i])
	{
		size_prev = size;
		size = ft_strlen(map[i]);
		if (size != size_prev)
			return (NO);
		++i;
	}
	return (YES);
}
