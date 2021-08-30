/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:33:58 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:34:06 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_first_column_closed(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		if (map[i][0] != '1')
			return (NO);
		++i;
	}
	return (YES);
}

static	int	is_first_line_closed(char **map)
{
	int	i;

	i = 0;
	while (map && map[0][i])
	{
		if (map[0][i] != '1')
			return (NO);
		++i;
	}
	return (YES);
}

static	int	is_last_column_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[0][i + 1])
		++i;
	while (map && map[j])
	{
		if (map[j][i] != '1')
			return (-1);
		++j;
	}
	return (YES);
}

static	int	is_last_line_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[j + 1])
		++j;
	while (map && map[j][i])
	{
		if (map[j][i] != '1')
			return (-1);
		++i;
	}
	return (YES);
}

int	is_map_closed(char **map)
{
	if (is_first_column_closed(map) == NO)
		return (NO);
	if (is_first_line_closed(map) == NO)
		return (NO);
	if (is_last_column_closed(map) == NO)
		return (NO);
	if (is_last_line_closed(map) == NO)
		return (NO);
	return (YES);
}
