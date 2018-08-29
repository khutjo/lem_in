/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 15:24:07 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/29 17:06:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

static	t_ant	*make(char *line, t_ant **head)
{
	t_ant *return_node;

	return_node = (t_ant *)malloc(sizeof(t_ant));
	return_node->line = line;
	return_node->next = NULL;
	if (!(*head))
		(*head) = return_node;
	return (return_node);
}

t_ant			*make_line(void)
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
			run = make(line, &head);
		else
		{
			run->next = make(line, &head);
			run = run->next;
		}
		if (!ft_strchr(line, '-') && !ft_strchr(line, '#') &&
				ft_strchr(line, ' '))
			comp++;
	}
	head->max = comp;
	return (head);
}

static	void	set_names(t_map *head, t_ant *lines)
{
	int		i;
	char	*temp;

	temp = NULL;
	i = ft_atoi(lines->line);
	while (lines && head)
	{
		if (ft_strstr(lines->line, "##start"))
		{
			head->start = 1;
			head->ants = i;
		}
		if (ft_strstr(lines->line, "##end"))
			head->end = 1;
		if (ft_strchr(lines->line, ' ') && !ft_strchr(lines->line, '#'))
		{
			head->name = ft_strdup(lines->line);
			temp = ft_strchr(head->name, ' ');
			temp[0] = '\0';
			head = head->next;
		}
		lines = lines->next;
	}
}

t_map			*make_map_node(t_ant *lines)
{
	int		i;
	t_map	*run;
	t_map	*head;
	t_map	*temp;

	run = NULL;
	head = NULL;
	i = lines->max;
	while (--i >= 0)
	{
		temp = (t_map *)malloc(sizeof(t_map));
		temp->start = 0;
		temp->end = 0;
		temp->next = NULL;
		if (!head)
			head = temp;
		else
			run->next = temp;
		run = temp;
	}
	set_names(head, lines);
	return (head);
}
