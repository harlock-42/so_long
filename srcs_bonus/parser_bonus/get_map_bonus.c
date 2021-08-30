/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:14:06 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 17:14:17 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	char	*cat_buff(char *str, void *buff)
{
	char	*new;
	char	*tmp;

	new = NULL;
	if (str)
		new = ft_strdup(str);
	else
		return (ft_strdup((char *)buff));
	tmp = new;
	new = ft_strjoin(new, (char *)buff);
	free(tmp);
	return (new);
}

static	char	*read_map(int fd)
{
	char	*str;
	char	*buffer[BUFFER_SIZE];
	int		ret;

	ret = 0;
	str = NULL;
	while (1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == (-1))
		{
			free(str);
			return (NULL);
		}
		str = cat_buff(str, buffer);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	**get_map(char *file_name)
{
	int		fd;
	char	*str;
	char	**map;

	str = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == (-1))
	{
		perror("");
		return (NULL);
	}
	str = read_map(fd);
	map = ft_split(str, '\n');
	free(str);
	if (map == NULL)
		return (NULL);
	return (map);
}
