/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_roll_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:24:56 by kmaputla          #+#    #+#             */
/*   Updated: 2018/08/29 16:43:27 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insect_lib.h"

int		am_i_done(t_ants *queen)
{
	t_ants	*run;
	t_map	*temp;

	run = queen;
	while (run)
	{
		temp = run->home;
		if (!temp->end)
		{
			return (1);
		}
		run = run->next;
	}
	return (0);
}

void	tally_of_ants(t_ants *queen, t_map *head)
{
	while (head)
	{
		head->ants = 0;
		head = head->next;
	}
	while (queen)
	{
		queen->home->ants++;
		queen = queen->next;
	}
}

void	print_out(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

void	ants_roll_out(t_ants *queen, t_map *head)
{
	t_ants	*scout_ant;
	t_map	*temp;
	int		end_round;

	while (am_i_done(queen))
	{
		scout_ant = queen;
		end_round = 1;
		while (scout_ant)
		{
			temp = scout_ant->home;
			temp = temp->tree[temp->best];
			if (!scout_ant->home->end && (temp->ants == 0 ||\
						(temp->end && end_round)))
			{
				end_round = (temp->end ? 0 : 1);
				scout_ant->home = temp;
				print_out(scout_ant->name, scout_ant->home->name);
			}
			scout_ant = scout_ant->next;
			tally_of_ants(queen, head);
		}
		ft_putchar('\n');
	}
}

void	best_route(t_map *head)
{
	int i;
	int num_move;

	i = 0;
	head->best = 0;
	if (!head->end)
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
	if (head->next)
		best_route(head->next);
}
