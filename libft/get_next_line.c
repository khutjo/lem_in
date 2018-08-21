/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:08:47 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/21 08:41:32 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	int		join(char **line)
{
	int		i;
	int		size;
	char	*temp;
	char	buf[2];

	i = 0;
	temp = NULL;
	buf[0] = '\0';
	buf[1] = '\0';
	size = read(0, buf, 1);
	if (!size || buf[0] == '\n')
		buf[0] = '\0';
	if ((*line) == NULL)
		(*line) = ft_strdup(buf);
	else if ((*line) != NULL)
	{
		temp = ft_strjoin((*line), buf);
		free((*line));
		(*line) = temp;
	}
	if (ft_strlen(*line) && buf[0] == '\0')
		return (2);
	return (size);
}

int				get_next_line(char **line)
{
	int				size;

	size = 1;
	(*line) = NULL;
	while (size == 1)
		size = join(line);
	if (size == 2)
		size = 1;
	return (size);
}
