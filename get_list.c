/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:24:07 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/21 16:51:35 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

static	t_ant	*make(char *line)
{
	t_ant *return_node;

	return_node = (t_ant *)malloc(sizeof(t_ant));
	return_node->line = line;
	return_node->next = NULL;
	return (return_node);
}

t_ant	*make_line(void)
{
	int		comp;
	char	*line;
	t_ant	*head;
	t_ant	*run;

	comp = 0;
	line = NULL;
	head = NULL;
	while (get_next_line(&line) == 1)
	{
		if (!head)
			run = (head = make(line));
		else
		{
			run->next = make(line);
			run = run->next;
		}
		if (comp < ft_atoi(line))
			comp = ft_atoi(line);
		run->max = comp;
	}
	return (head);
}

t_map		*make_map_node(t_ant *lines)
{
	int		i;
	t_map	*run;
	t_map	*head;
	t_map	*temp;

	run = NULL;
	head = NULL;
	while (lines->next)
		lines = lines->next;
	i = lines->max;
	while (--i >= 0)
	{
		temp = (t_map *)malloc(sizeof(t_map));
		temp->name = ft_itoa(i);
		temp->next = NULL;
		if (!head)
			run = (head = temp);
		else
		{
			run->next = temp;
			run = temp;
		}
	}
	return (head);
}


