/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:34:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/21 18:03:20 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"
#include <stdio.h>

int		num_of_links(t_ant *lines, char *name)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(name);
	while (lines)
	{
		if (ft_strchr(lines->line, '-') && ft_strstr(lines->line, name))
			i++;
		lines = lines->next;
	}
	return (i);
}

t_map	*put_link(t_map *head, t_map *run, char *link)
{
	int stop;

	stop = 0;
	while (link[stop] && link[stop] != '-')
		stop++;
	if (ft_strstr(&link[stop], head->name))
	{
		printf("========> %s <> %d <========\n", run->name, stop);
		while (!ft_strnstr(link, run->name, stop) && run)
		{
			printf("========> %s <========\n", run->name);
			run = run->next;
		}
	}
	else
		while (!ft_strstr(&link[stop], run->name) && run)
			run = run->next;
	return (run);
}

void	map(t_map *head, t_ant *lines)
{
	int		i;
	int		links_num;
	t_map	*run_line;

	i = 0;
	links_num = num_of_links(lines, head->name);
	head->tree = (t_map **)malloc(sizeof(t_map **) * (1 + links_num));
	head->tree[links_num] = NULL;
	while (!ft_strchr(lines->line, '-'))
		lines = lines->next;
	while (lines)
	{
		printf("====> %s <====\n", lines->line);
		if (ft_strstr(lines->line, head->name))
		{
			printf("%s <> %s <> %d <> %d\n", lines->line, head->name, i, links_num);
			head->tree[i++] = put_link(head, head, lines->line);
			printf("%s <> %s <> %d\n", lines->line, head->name, i);
		}
		lines = lines->next;
	}
}

int  main(void)
{
	int		i;
	int		high;
	t_ant	*temp;
	t_map	*head;
	t_map	*run;

	i = 0;
	head = NULL;
	temp = make_line();
	run = (head = make_map_node(temp));
	while (run)
	{
		ft_putstr(run->name);
		ft_putstr("\n");
		run = run->next;
	}
	map(head, temp);
	while (head->tree[i])
	{
		run = head->tree[i++];
		ft_putstr(run->name);
		ft_putstr("\n");
	}
	return (0);
}
