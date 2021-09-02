/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:30:23 by tallaire          #+#    #+#             */
/*   Updated: 2021/08/30 16:30:46 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	char	*cat_buff(char *str, char *buff)
{
	char	*new;
	char	*tmp;

	new = NULL;
	tmp = NULL;
	if (str)
		new = ft_strdup(str);
	else
		return (ft_strdup(buff));
	tmp = new;
	new = ft_strjoin(new, buff);
	free(tmp);
	return (new);
}

static	char	*read_map(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE];
	int		ret;

	ret = 0;
	str = NULL;
	ft_bzero(buffer, BUFFER_SIZE);
	while (1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
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

static	int	is_only_lf(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '\n')
			return (NO);
		++i;
	}
	return (YES);
}

static	int	get_fd(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != (-1))
	{
		sl_error("file.map should not be a directory");
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd == (-1))
	{
		ft_printf("%sError%s\n", RED, NC);
		perror("");
		return (-1);
	}
	return (fd);
}

char	**get_map(char *file_name)
{
	int		fd;
	char	*str;
	char	**map;

	str = NULL;
	fd = get_fd(file_name);
	if (fd == (-1))
		return (NULL);
	str = read_map(fd);
	if (is_only_lf(str) == YES)
	{
		sl_error("There is no map in file.ber");
		return (NULL);
	}
	map = ft_split(str, '\n');
	free(str);
	if (map == NULL)
		return (NULL);
	return (map);
}
