/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:34:28 by kmaputla          #+#    #+#             */
/*   Updated: 2018/09/07 16:05:34 by kmaputla         ###   ########.fr       */
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

void	mid_run(t_map *head, t_ants *queen)
{
	t_ants	*run;

	while (head && !head->start)
		head = head->next;
	run = queen;
	while (run)
	{
		run->home = NULL;
		run = run->next;
	}
	ants_roll_out(queen, head->moves[head->best]);
}

void	best_route(t_map *head, t_ants *queen)
{
	int i;
	int num_move;

	i = 0;
	head->best = 0;
	while (head && !head->start)
		head = head->next;
	if (head)
	{
		head->ants = 0;
		num_move = head->moves[i]->num_move;
		while (head->moves[++i])
			if (num_move > head->moves[i]->num_move || num_move == -1)
			{
				num_move = head->moves[i]->num_move;
				head->best = i;
			}
	}
	while (queen)
	{
		queen->home = head->moves[head->best];
		queen = queen->next;
	}
}

int		main(void)
{
	t_ant	*temp_ant;
	t_map	*head;
	t_ants	*queen;

	head = NULL;
	temp_ant = make_line();
	is_it_cool(temp_ant);
	head = make_map_node(temp_ant);
	map(head, temp_ant);
	lay_ant_eggs(temp_ant, &queen);
	find_end(head);
	is_there_an_end(head);
	best_route(head, queen);
	map_comp(temp_ant);
	mid_run(head, queen);
	free_lines(&temp_ant);
	free_joogle_maps(&head);
	set_the_queen_free(&queen);
	return (0);
}
