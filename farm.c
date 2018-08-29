/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:34:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/29 16:34:39 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"
#include <stdio.h>

void	is_there_an_end(t_map *head)
{
	int i;

	i = -1;
	while (head && !head->start)
		head = head->next;
	while (head->moves[++i])
		if (head->moves[i]->exit)
			return ;
	no();
}

void	map_comp(t_ant *line)
{
	while (line)
	{
		ft_putendl(line->line);
		line = line->next;
	}
	ft_putchar('\n');
}

int		main(void)
{
	t_ant	*temp_ant;
	t_map	*head;
	t_ants	*queen;
	t_map	*free_map;

	head = NULL;
	temp_ant = make_line();
	is_it_cool(temp_ant);
	head = make_map_node(temp_ant);
	free_map = head;
	map(head, temp_ant);
	lay_ant_eggs(head, &queen);
	find_end(head);
	is_there_an_end(head);
	best_route(head);
	map_comp(temp_ant);
	ants_roll_out(queen, head);
	free_lines(&temp_ant);
	free_joogle_maps(&free_map);
	set_the_queen_free(&queen);
	return (0);
}
