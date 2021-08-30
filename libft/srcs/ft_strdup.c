/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:00:03 by tallaire          #+#    #+#             */
/*   Updated: 2021/05/31 15:42:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char    *ft_strdup(const char *src)
{
    int        i;
    char    *dest;

    if (!src)
        return (NULL);
    i = 0;
    while (src[i])
        i++;
    dest = malloc(sizeof(char) * (i + 1));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
