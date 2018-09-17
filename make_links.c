/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:55:49 by kmaputla          #+#    #+#             */
/*   Updated: 2018/09/07 16:01:25 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

static	int		num_of_links(t_ant *lines, char *name)
{
	int i;

	i = 0;
	while (lines)
	{
		if (ft_strchr(lines->line, '-') && ft_strstr(lines->line, name))
			i++;
		lines = lines->next;
	}
	return (i);
}

static	t_map	*put_link(t_map *head, t_map *run, char *link)
{
	int stop;

	stop = 0;
	while (link[stop] && link[stop] != '-')
		stop++;
	if (ft_strequ(&link[1 + stop], head->name))
	{
		while (run && !ft_strnequ(link, run->name, stop) && head)
			run = run->next;
	}
	else
		while (run && !ft_strequ(&link[1 + stop], run->name) && run)
			run = run->next;
	if (!run)
		no();
	return (run);
}

static	void	find_link(t_map *head, t_map *set_link, t_ant *lines)
{
	int		i;
	int		dash;
	int		links_num;

	i = 0;
	links_num = num_of_links(lines, set_link->name);
	set_link->tree = (t_map **)malloc(sizeof(t_map *) * (1 + links_num));
	set_link->tree[links_num] = NULL;
	while (!ft_strchr(lines->line, '-'))
		lines = lines->next;
	while (lines)
	{
		dash = 0;
		while (lines->line[dash] && lines->line[dash] != '-')
			dash++;
		if (ft_strstr(lines->line, set_link->name))
			set_link->tree[i++] = put_link(set_link, head, lines->line);
		lines = lines->next;
	}
}

void			map(t_map *head, t_ant *lines)
{
	t_map	*list_runner;
	t_ant	*line;
	int		i;

	i = 0;
	line = lines;
	while (line && !ft_strchr(line->line, '-'))
		line = line->next;
	while (line && (ft_strchr(line->line, '-') || line->line[0] == '#'))
		line = line->next;
	(line ? no() : 0);
	list_runner = head;
	while (list_runner)
	{
		find_link(head, list_runner, lines);
		list_runner = list_runner->next;
	}
}

void			lay_ant_eggs(t_ant *lines, t_ants **queen_ant)
{
	int		i;
	int		num;
	t_ants	*run;
	t_ants	*temp;

	i = -1;
	(*queen_ant) = NULL;
	while (lines && lines->line[0] == '#')
		lines = lines->next;
	num = ft_atoi(lines->line);
	while (++i < num)
	{
		temp = (t_ants *)malloc(sizeof(t_ants));
		if (!(*queen_ant))
			(*queen_ant) = temp;
		else
			run->next = temp;
		run = temp;
		temp->name = 1 + i;
	}
}
